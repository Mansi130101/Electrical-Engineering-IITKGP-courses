function dxdt = pen2(t,x)
dxdt_1=x(2);
dxdt_2=-0.3*x(2)-12.25*sin(x(1));
dxdt=[dxdt_1;dxdt_2];
end