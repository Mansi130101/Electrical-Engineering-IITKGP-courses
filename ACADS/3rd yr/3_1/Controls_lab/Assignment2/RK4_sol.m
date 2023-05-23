function [t,y] = RK4_sol(f,t0,t1,y0,h)
t=t0:h:t1;
l1=length(t);
l2=length(y0);
y=zeros([l2,l1]);
y(:,1)=transpose(y0);
for i = 2:l1
    s1=f(t(i-1),y(:,i-1));
    s2=f(t(i-1)+h/2,y(:,i-1)+h.*s1./2);
    s3=f(t(i-1)+h/2,y(:,i-1)+h.*s2./2);
    s4=f(t(i-1)+h,y(:,i-1)+h.*s3);
    y(:,i)=y(:,i-1)+(s1+2.*s2+2.*s3+s4).*h./6;
end
end