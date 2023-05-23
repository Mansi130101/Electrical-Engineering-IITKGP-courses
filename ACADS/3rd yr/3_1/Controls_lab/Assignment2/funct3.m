function f = funct3(t,y,g,l)
f = zeros(2,1);
f(1) = y(2);
f(2) = - (g/l) * sin(y(1)); 
end