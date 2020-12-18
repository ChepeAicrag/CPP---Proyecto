fs = 10;
ts = 1 / fs;
T = [0:ts:1];
y = sin(2*pi*T)

subplot(2,1,1);
plot(T,y);
title('Señal Muestreada');
xlabel('Tiempo');
ylabel('Amplitud');

tf =fft(y)

subplot(2,1,2)
plot(T,tf)