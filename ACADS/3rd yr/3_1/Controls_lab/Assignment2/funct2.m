function [t,y, time_elapsed] = funct2(funct, time_interval, y0, h)
tic
t = [time_interval(1)];
y = [y0];
n=1;
while t(n) < time_interval(2)
    s1 = funct(t(n),y(n,:))';
    s2 = funct(t(n)+h/2,y(n,:)+s1*(h/2))';
    s3 = funct(t(n)+h/2,y(n,:)+s2*(h/2))';
    s4 = funct(t(n)+h,y(n,:)+h*s3)';
    y(n+1,:) = y(n,:) + (h/6)*(s1+2*s2+2*s3+s4);
    t(n+1) = t(n)+h;
    n=n+1;
end
y= y';

time_elapsed=toc;
end