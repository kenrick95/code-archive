import sys, pygame
from pygame.locals import *

pygame.init()
pygame.display.set_caption('IPSC test')
font   = pygame.font.Font(None, 24)
logo   = pygame.image.load('ipsc.png')
size   = width, height = 800, 600
screen = pygame.display.set_mode(size)

background = pygame.Surface(screen.get_size())
background = background.convert()
background.fill((255,255,255))
screen.blit(background, (0,0))
screen.blit(logo, (304,236))
        
screen.blit( font.render('All OK', 1, (0,0,0)), (350,400) )

pygame.display.flip()

while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT or event.type == MOUSEBUTTONDOWN:
            pygame.mouse.set_visible(1)
            pygame.event.set_grab(0)
            sys.exit()
        elif event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                pygame.mouse.set_visible(1)
                pygame.event.set_grab(0)
                sys.exit()
