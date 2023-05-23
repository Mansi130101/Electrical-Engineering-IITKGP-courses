function [t,y] = euler_sol(f,t0,t1,y0,h)
t=t0:h:t1;
l1=length(t);
l2=length(y0);
y=zeros([l2,l1]);
y(:,1)=transpose(y0);
for i = 2:l1
    y(:,i)=y(:,i-1)+h.*f(t(i-1),y(:,i-1));
end
end