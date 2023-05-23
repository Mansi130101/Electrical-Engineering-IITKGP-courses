tf1 = tf(1, [1, 6, 45, 0]);
tf2 = tf([0.075, 1, 1], [1, 3, 5, 0]);
K = 40;
sys1 = (K* tf1)/(1 + K * tf1);
sys2 = (K* tf2)/(1 + K * tf2);
step(sys1, 'r', sys2, 'b')
hold on;
legend('tf1','tf2');
grid on;
info1 = stepinfo(sys1)
info2 = stepinfo(sys2)