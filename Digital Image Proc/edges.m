function edges(Image)  
img =imread(Image);
figure, imshow(img);

robertx=[1 0; 0 -1];
roberty=[0 1;-1 0];
sobelx=[-1 0 1; -2 0 2; -1 0 1];
sobely=[-1 -2 -1;0 0 0; 1 2 1];
prewittx=[-1 0 -1; -1 0 1; -1 0 1];
prewitty=[-1 -1 -1;0 0 0; 1 1 1];

robert=abs(convolution(img,robertx))+abs(convolution(img,roberty));
sobel=abs(convolution(img,sobelx))+abs(convolution(img,sobely));
prewitt=abs(convolution(img,prewittx))+abs(convolution(img,prewitty));

figure, imshow(robert);
figure,imshow(prewitt);
figure, imshow(sobel);


