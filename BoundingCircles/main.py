"""Bound the circle's with a rectangle

input is x, y, radius
output is x,y for each point in rectangle

input:
1, 1, 2
2, 2, 0.5
-1, -3, 2
5, 2, 1

output:
(-3, -5), (-3, 3), (6, 3), (6, -5)
"""
from PIL import Image

class Circle:
    
    def __init__(self):
        self.x = float(input('X > '))
        self.y = float(input('Y > '))
        self.radius = float(input('Radius > '))
        

def main(circles):
    color_format = 'RGB'
    image_background = 'white'
    size = (500, 500)
    outfile = 'image.jpg'
    outformat = 'JPEG'
    
    img = Image.new(color_format, size, image_background)
    
    # -- Try to make this generate an image --
    
    clis = []
    for i in range(circles):
        clis.append(Circle())
        
    top_x = -10000.0
    top_y = -10000.0
    bot_x = 10000.0
    bot_y = 10000.0
    
    for i in clis:
        if i.x + i.radius > top_x:
            top_x = i.x + i.radius
        if i.y + i.radius > top_y:
            top_y = i.y + i.radius
        if i.x - i.radius < bot_x:
            bot_x = i.x - i.radius
        if i.y - i.radius < bot_y:
            bot_y = i.y - i.radius
            
    # Build the rectangle
    rectangle = ((top_x, top_y),
                 (top_x, bot_y),
                 (bot_x, top_y),
                 (bot_x, bot_y))
    
    print('Rectangle: {}'.format(rectangle))
    
    

if __name__ == '__main__':
    main(4)
