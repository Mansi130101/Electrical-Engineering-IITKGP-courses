sys = zpk(-3, [0, -5, -6, -1+1i, -1-1i], 1);
rlocus(sys)