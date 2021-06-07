function  Img2=convolution(Img, mask)

Img2=rgb2gray(Img);
Img3=double(Img2);
[a, b]=size(Img3);
[n,~]=size(mask);

for i=1:a-2
    for j=1:b-2
        conv=Img3(i:i+(n-1),j:j+(n-1))*mask;
        s=sum(sum(conv));
        Img2(i,j)=s;                    
    end
end