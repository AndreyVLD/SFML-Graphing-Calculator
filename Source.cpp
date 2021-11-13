#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "mate.h"
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace sf;

double latime, lungime;
bool wait=1;
double i, fy, fx, pr, zoom;
int met, func, mx, my;

Text v[10];

struct v2int
{
    float x, y;
}cntr;

RenderWindow window(VideoMode(1300, 800), "Graphing Calculator", Style::Default);

//values for window
void valsw()
{
    latime = window.getSize().y;
    lungime = window.getSize().x;
    v[1].setCharacterSize(window.getSize().y / 35);
    v[2].setCharacterSize(window.getSize().y / 35);
    cntr.x = lungime / 2.f;
    cntr.y = latime / 2.f;

}
int main()
{
    valsw();
    //window settings
    window.setFramerateLimit(30);
    window.setPosition(Vector2i(0, 0));

    //objects
    VertexArray pct(Points, 1);
    VertexArray pc2(Lines, 2);
    VertexArray Ox(Quads, 4);
    Ox[0].position.y = cntr.y + 1.f;
    Ox[0].position.x = 0.f;
    Ox[1].position.y = cntr.y - 1.f;
    Ox[1].position.x = 0.f;
    Ox[2].position.x = lungime;
    Ox[2].position.y = cntr.y - 1.f;
    Ox[3].position.x = lungime;
    Ox[3].position.y = cntr.y + 1.f;
    for (i = 0; i <= 3; i++)
        Ox[i].color = Color::Red;

    VertexArray Oy(Quads, 4);
    Oy[0].position.x = cntr.x + 1.f;
    Oy[0].position.y = 0.f;
    Oy[1].position.x = cntr.x - 1.f;
    Oy[1].position.y = 0.f;
    Oy[2].position.y = latime;
    Oy[2].position.x = cntr.x - 1.f;
    Oy[3].position.y = latime;
    Oy[3].position.x = cntr.x + 1.f;
    for (i = 0; i <= 3; i++)
        Oy[i].color = Color::Red;
    RectangleShape back(Vector2f(lungime, latime));
    back.setFillColor(Color(0, 122, 204, 255));
    back.setPosition(0, 0);

    RectangleShape sele(Vector2f(20, 16));
    sele.setFillColor(Color(165, 206, 230, 255));
    sele.setPosition(0, 0);

    //fonts and text
    Font font;
    if (!font.loadFromFile("Resources/Fonts/arial.ttf"))
        return -1;

    v[1].setFont(font);
    v[1].setString("x^2 | x^3 | sqrt(x) |  2^x  | log(x) | abs(x) | 1/x");
    v[1].setFillColor(Color::Red);
    v[1].setPosition(Vector2f(10, 0));

    v[2].setFont(font);
    v[2].setString("Press Space to reset calculator");
    v[2].setFillColor(Color::Red);
    v[2].setPosition(Vector2f(lungime-320, 0));

    //main loop
    while (window.isOpen())
    {
        wait = 1;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::Resized)
                valsw();
            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Escape)
                    window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    mx = Mouse::getPosition(window).x;
                    my = Mouse::getPosition(window).y;
                }
                if (my >= 0 && my <= 32)
                {
                    wait = 0;
                    if (mx >= 7 && mx < 49)
                    {
                        func = 1, wait = 0;
                    }
                    if (mx >= 49 && mx < 100)
                    {
                        func = 2, wait = 0;
                    }
                    if (mx >= 100 && mx < 186)
                    {
                        func = 3, wait = 0;
                    }
                    if (mx >= 186 && mx < 247)
                    {
                        func = 4, wait = 0;
                    }
                    if (mx >= 250 && mx < 320)
                    {
                        func = 5, wait = 0;
                    }
                    if (mx >= 320 && mx < 400)
                    {
                        func = 6, wait = 0;
                    }
                    if (mx >= 400 && mx < 480)
                    {
                        func = 7, wait = 0;
                    }
                }
            }
        }
        window.clear();

        //draw
        window.draw(back);
        if (Mouse::getPosition(window).x >= 7 && Mouse::getPosition(window).x < 49 && Mouse::getPosition(window).y>=0 && Mouse::getPosition(window).y < 32)
        {
            sele.setPosition(Vector2f(7, 0));
            sele.setSize(Vector2f(45, 30));
            window.draw(sele);
        }
        else
            if(Mouse::getPosition(window).x >= 49 && Mouse::getPosition(window).x <100 && Mouse::getPosition(window).y>=0 && Mouse::getPosition(window).y < 32)
            {
                sele.setPosition(Vector2f(52, 0));
                sele.setSize(Vector2f(50, 30));
                window.draw(sele);
            }
            else
                if (Mouse::getPosition(window).x >= 100 && Mouse::getPosition(window).x < 186 && Mouse::getPosition(window).y >= 0 && Mouse::getPosition(window).y < 32)
                {
                    sele.setPosition(Vector2f(103, 0));
                    sele.setSize(Vector2f(82, 30));
                    window.draw(sele);
                }
                else
                    if (Mouse::getPosition(window).x >= 186 && Mouse::getPosition(window).x < 247 && Mouse::getPosition(window).y >= 0 && Mouse::getPosition(window).y < 32)
                    {
                        sele.setPosition(Vector2f(186, 0));
                        sele.setSize(Vector2f(61, 30));
                        window.draw(sele);
                    }
                    else
                        if (Mouse::getPosition(window).x >= 250 && Mouse::getPosition(window).x < 320 && Mouse::getPosition(window).y >= 0 && Mouse::getPosition(window).y < 32)
                        {
                            sele.setPosition(Vector2f(247, 0));
                            sele.setSize(Vector2f(77, 30));
                            window.draw(sele);
                        }
                        else
                            if(Mouse::getPosition(window).x >= 320 && Mouse::getPosition(window).x < 400 && Mouse::getPosition(window).y >= 0 && Mouse::getPosition(window).y < 32)
                            {
                                sele.setPosition(Vector2f(320, 0));
                                sele.setSize(Vector2f(79, 30));
                                window.draw(sele);
                            }
                            else
                                if(Mouse::getPosition(window).x >= 400 && Mouse::getPosition(window).x < 480 && Mouse::getPosition(window).y >= 0 && Mouse::getPosition(window).y < 32)
                                {
                                    sele.setPosition(Vector2f(400, 0));
                                    sele.setSize(Vector2f(50, 30));
                                    window.draw(sele);
                                }
        window.draw(Ox);
        window.draw(Oy);
        window.draw(v[1]);
        window.draw(v[2]);

        if (wait == 0 )
        {
            wait = 1;
            pr = 0.01;
            if (func == 5)
                pr = 0.005;
            for (i = -lungime; i <= lungime; i = i + pr)
            {
                if (event.type == Event::Resized)
                    valsw();
                if (func == 1)
                {
                    fx = i;
                    fy = x2(fx);
                    met = 2;
                }
                else
                    if (func == 2)
                    {
                        fx = i;
                        fy = x3(fx);
                        met = 2;
                    }
                    else
                        if (func == 3)
                        {
                            fx = i;
                            fy = sqrtx(fx);
                            met = 2;
                        }
                        else
                            if (func == 4)
                            {
                                fx = i;
                                fy = xp2(fx);
                                met = 1;
                            }
                            else
                                if (func == 5)
                                {
                                    fx = i;
                                    fy = lnx(fx);
                                    met = 2;
                                }
                                else
                                    if (func == 6)
                                    {
                                        fx = i;
                                        fy = abs(i);
                                        met = 1;
                                    }
                                    else
                                        if (func == 7)
                                        {
                                            fx = i;
                                            fy = x1(i);
                                            met = 1;
                                        }
                if (int(fy) - fy != 0)
                    fy = int(fy);
                if (met == 1)
                {
                    pct[0].position.x = fx + cntr.x;
                    pct[0].position.y = -fy + cntr.y;
                    window.draw(pct);
                }
                else
                {
                    if (func == 1)
                    {
                        pc2[0].position.x = fx + cntr.x;
                        pc2[0].position.y = -fy + cntr.y;
                        i++;
                        fx = i;
                        fy = x2(fx);
                        pc2[1].position.x = fx + cntr.x;
                        pc2[1].position.y = -fy + cntr.y;
                        i--;
                    }
                    else
                        if (func == 2)
                        {
                            pc2[0].position.x = fx + cntr.x;
                            pc2[0].position.y = -fy + cntr.y;
                            i++;
                            fx = i;
                            fy = x3(fx);
                            pc2[1].position.x = fx + cntr.x;
                            pc2[1].position.y = -fy + cntr.y;
                            i--;
                        }
                        else
                            if (func == 3 && i>=0)
                            {
                                pc2[0].position.x = fx + cntr.x;
                                pc2[0].position.y = -fy + cntr.y;
                                i++;
                                fx = i;
                                fy = sqrtx(fx);
                                pc2[1].position.x = fx + cntr.x;
                                pc2[1].position.y = -fy + cntr.y;
                                i--;
                            }
                            else
                                if (func == 5 && i>=0)
                                {
                                    pc2[0].position.x = fx + cntr.x;
                                    pc2[0].position.y = -fy + cntr.y;
                                    i++;
                                    fx = i;
                                    fy = lnx(fx);
                                    pc2[1].position.x = fx + cntr.x;
                                    pc2[1].position.y = -fy + cntr.y;
                                    i--;
                                }
                    window.draw(pc2);
                }
            }
            window.display();
            while (true)
                if (Keyboard::isKeyPressed(Keyboard::Space))
                    break;
        }
       //display
       window.display();
    }
    return 0;
}
