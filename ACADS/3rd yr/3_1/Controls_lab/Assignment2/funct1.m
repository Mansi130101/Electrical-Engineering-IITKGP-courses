function [t,y, time_elapsed] = funct1(funct, time_interval, y0, h)
tic;
t = [time_interval(1)];
y = [y0];
n=1;
while t(n) < time_interval(2)
    y(n+1,:) = y(n,:) + h*funct(t(n),y(n,:))';
    t(n+1) = t(n)+h;
    n=n+1;
end
y= y';
time_elapsed=toc;
end
