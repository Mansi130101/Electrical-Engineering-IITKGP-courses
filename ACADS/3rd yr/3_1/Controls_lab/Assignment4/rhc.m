function y=rhc(coeffVector,x)
ceoffLength = length(coeffVector);
rhTableColumn = round(ceoffLength/2);
rhTable = zeros(ceoffLength,rhTableColumn);
rhTable(1,:) = coeffVector(1,1:2:ceoffLength);
if (rem(ceoffLength,2) ~= 0)
    rhTable(2,1:rhTableColumn - 1) = coeffVector(1,2:2:ceoffLength);
else
    rhTable(2,:) = coeffVector(1,2:2:ceoffLength);
end
epss=0.0001;
for i = 3:ceoffLength
    if rhTable(i-1,:) == 0
        order = (ceoffLength - i);
        cnt1 = 0;
        cnt2 = 1;
        for j = 1:rhTableColumn - 1
            rhTable(i-1,j) = (order - cnt1) * rhTable(i-2,cnt2);
            cnt2 = cnt2 + 1;
            cnt1 = cnt1 + 2;
        end
    end
    for j = 1:rhTableColumn - 1
        firstElemUpperRow = rhTable(i-1,1);
        rhTable(i,j) = ((rhTable(i-1,1) * rhTable(i-2,j+1))-(rhTable(i-2,1) * rhTable(i-1,j+1))) / firstElemUpperRow;
    end
    if rhTable(i,1) == 0
        rhTable(i,1) = epss;
    end
end
unstablePoles = 0;
for i = 1:ceoffLength - 1
    if sign(rhTable(i,1)) * sign(rhTable(i+1,1)) == -1
        unstablePoles = unstablePoles + 1;
    end
end
if x==1
    fprintf('\n Routh-Hurwitz Table:\n')
    rhTable %#ok<NOPRT>
end
if unstablePoles == 0
    y=1;
else
    y=0;
end
end

