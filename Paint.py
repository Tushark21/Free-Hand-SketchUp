import pygame,sys
from pygame.locals import *

pygame.init()

maxx=1200#getx()
maxy=900#gety()
canvas=pygame.display.set_mode((maxx,maxy),0,32)

pygame.display.set_caption('Mouse Input')
white=(255,255,255)
col=(0,0,0)
canvas.fill(white)
up=0
x1=0
y1=0

while True:

    for event in pygame.event.get():

        if event.type==QUIT:
            pygame.quit()
            sys.exit()

        if event.type==MOUSEBUTTONDOWN:
            x1=event.pos[0]
            y1=event.pos[1]
            up=1;
            
        if event.type==MOUSEBUTTONUP:
            up=0;

        if event.type==MOUSEMOTION and up==1:
                x=event.pos[0]
                y=event.pos[1]
                pygame.draw.line(canvas,col,(x1,y1),(x,y),1)
                x1=x
                y1=y

        pygame.display.update()
