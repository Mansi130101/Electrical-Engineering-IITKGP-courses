function dxdt=pen1(t,x)
dxdt_1=x(2);
dxdt_2=-4.9*sin(x(1));
dxdt=[dxdt_1;dxdt_2];
end