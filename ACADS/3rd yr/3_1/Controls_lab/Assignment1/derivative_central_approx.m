function [y] = derivative_central_approx (f,x,h)
y=(f(x+h)-f(x-h))/(2*h);
end