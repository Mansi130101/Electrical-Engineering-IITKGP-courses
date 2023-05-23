function func = funct4(t,y,g,L,m,b)
func = zeros(2,1);
func(1) = y(2);
func(2) = -(b/m)*y(2) - ((m*g)/(L*(m-2*b))) * sin(y(1)); 
end