sys = zpk(-1, [0, 1, -2+sqrt(3)*2i, -2-sqrt(3)*2i], 1);
rlocus(sys)