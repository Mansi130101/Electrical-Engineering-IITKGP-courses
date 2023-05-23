sys = zpk(-1, [0, -4, -1+1i, -1-1i], 1);
rlocus(sys)