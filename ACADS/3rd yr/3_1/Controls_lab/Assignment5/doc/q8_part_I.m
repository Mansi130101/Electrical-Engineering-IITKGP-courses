sys1 = tf(1, [1, 6, 45, 0]);
sys2 = tf([0.075, 1, 1], [1, 3, 5, 0]);
%rlocus(sys1)
rlocus(sys2)