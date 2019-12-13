    #include <windows.h>
    #ifdef __APPLE__
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif

    #include <stdlib.h>

    #include<stdio.h>
    //#include<GL/glut.h>
    #include <GL/gl.h>
    //#include <stdlib.h>

    #define SPEED 40.0      //speed of traffic

    float i=0.0;            //movement of car
    float m=0.0;            //movement of clouds
    float n=0.0;            //movement of plane along x-axis
    float o=0.0;            //and y-axis
    float c=0.0;            //movement of comet	SS

    int light=1;            //1 for green-light, 0 for red-light
    int day=1;              //1 for day ,0 for night
    int plane=0;            //1 for plane
    int comet=0;            //1 for comet


    void draw_pixel(GLint cx, GLint cy)
    {
        glBegin(GL_POINTS);
            glVertex2i(cx,cy);
        glEnd();
    }

    void plotpixels(GLint h,GLint k, GLint x,GLint y)
    {
        draw_pixel(x+h,y+k);
        draw_pixel(-x+h,y+k);
        draw_pixel(x+h,-y+k);
        draw_pixel(-x+h,-y+k);
        draw_pixel(y+h,x+k);
        draw_pixel(-y+h,x+k);
        draw_pixel(y+h,-x+k);
        draw_pixel(-y+h,-x+k);
    }

    void draw_circle(GLint h, GLint k, GLint r)
    {
        GLint d=1-r, x=0, y=r;
        while(y>x)
        {
            plotpixels(h,k,x,y);
            if(d<0)
                d+=2*x+3;
            else
            {
                d+=2*(x-y)+5;
                --y;
            }
            ++x;
        }
        plotpixels(h,k,x,y);
    }


    void draw_object()
    {
        int l;
        if(day==1)
        {
            //sky
            glColor3f(0.0,0.9,0.9);
            glBegin(GL_POLYGON);
            glVertex3f(0,450,0);
            glVertex3f(0,700,0);
            glVertex3f(1100,700,0);
            glVertex3f(1100,450,0);
        glEnd();

            //sun
            for(l=0;l<=35;l++)
            {
                glColor3f(1.0,0.9,0.0);
                draw_circle(100,625,l);
            }


            //plane
            if(plane==1)
            {
                glColor3f(1.0,1.0,1.0);
                glBegin(GL_POLYGON);
                    glVertex3f(925+n,625+o,0);
                    glVertex3f(950+n,640+o,0);
                    glVertex3f(1015+n,640+o,0);
                    glVertex3f(1030+n,650+o,0);
                    glVertex3f(1050+n,650+o,0);
                    glVertex3f(1010+n,625+o,0);
                glEnd();

                glColor3f(0.8,0.8,0.8);
                glBegin(GL_LINE_LOOP);
                    glVertex3f(925+n,625+o,0);
                    glVertex3f(950+n,640+o,0);
                    glVertex3f(1015+n,640+o,0);
                    glVertex3f(1030+n,650+o,0);
                    glVertex3f(1050+n,650+o,0);
                    glVertex3f(1010+n,625+o,0);
                glEnd();

            }

            //cloud1
            for(l=0;l<=20;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(160+m,625,l);
            }


            for(l=0;l<=35;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(200+m,625,l);
                draw_circle(225+m,625,l);
            }

            for(l=0;l<=20;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(265+m,625,l);
            }

            //cloud2
            for(l=0;l<=20;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(370+m,615,l);
            }

            for(l=0;l<=35;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(410+m,615,l);
                draw_circle(435+m,615,l);
                draw_circle(470+m,615,l);
            }

            for(l=0;l<=20;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(500+m,615,l);
            }
            //grass
            glColor3f(0.0,1.0,0.0);
            glBegin(GL_POLYGON);
                glVertex3f(0,160,0);
                glVertex3f(0,450,0);
                glVertex3f(1100,450,0);
                glVertex3f(1100,160,-0);
            glEnd();

            //pond
            glColor3f(0.0,0.9,0.9);
            glBegin(GL_POLYGON);
                glVertex3f(25,350,0);
                glVertex3f(25,375,0);
                glVertex3f(50,400,0);
                glVertex3f(75,410,0);
                glVertex3f(100,420,0);
                glVertex3f(200,420,0);
                glVertex3f(225,410,0);
                glVertex3f(250,405,0);
                glVertex3f(275,390,0);
                glVertex3f(300,375,0);
                glVertex3f(310,350,0);
                glVertex3f(300,320,0);
                glVertex3f(275,300,0);
                glVertex3f(250,295,0);
                glVertex3f(225,290,0);
                glVertex3f(200,285,0);
                glVertex3f(175,280,0);
                glVertex3f(150,280,0);
                glVertex3f(125,280,0);
                glVertex3f(100,290,0);
                glVertex3f(75,300,0);
                glVertex3f(50,310,0);
            glEnd();

        }
        else
        {
            //sky
            glColor3f(0.0,0.0,0.0);
            glBegin(GL_POLYGON);
                glVertex3f(0,450,0);
                glVertex3f(0,700,0);
                glVertex3f(1100,700,0);
                glVertex3f(1100,450,0);
            glEnd();

            //moon
            int l;

            for(l=0;l<=35;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(100,625,l);
            }

            //star1
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(575,653,0);
                glVertex3f(570,645,0);
                glVertex3f(580,645,0);
                glVertex3f(575,642,0);
                glVertex3f(570,650,0);
                glVertex3f(580,650,0);
            glEnd();

            //star2
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(975,643,0);
                glVertex3f(970,635,0);
                glVertex3f(980,635,0);
                glVertex3f(975,632,0);
                glVertex3f(970,640,0);
                glVertex3f(980,640,0);
            glEnd();

            //star3
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(875,543,0);
                glVertex3f(870,535,0);
                glVertex3f(880,535,0);
                glVertex3f(875,532,0);
                glVertex3f(870,540,0);
                glVertex3f(880,540,0);
            glEnd();

            //star4
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(375,598,0);
                glVertex3f(370,590,0);
                glVertex3f(380,590,0);
                glVertex3f(375,587,0);
                glVertex3f(370,595,0);
                glVertex3f(380,595,0);
            glEnd();

            //star5
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(750,628,0);
                glVertex3f(745,620,0);
                glVertex3f(755,620,0);
                glVertex3f(750,618,0);
                glVertex3f(745,625,0);
                glVertex3f(755,625,0);
            glEnd();

            //star6
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(200,628,0);
                glVertex3f(195,620,0);
                glVertex3f(205,620,0);
                glVertex3f(200,618,0);
                glVertex3f(195,625,0);
                glVertex3f(205,625,0);
            glEnd();

            //star7
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(500,543,0);
                glVertex3f(495,535,0);
                glVertex3f(505,535,0);
                glVertex3f(500,532,0);
                glVertex3f(495,540,0);
                glVertex3f(505,540,0);
            glEnd();

            //comet
            if(comet==1)
            {
                for(l=0;l<=7;l++)
                {
                    glColor3f(1.0,1.0,1.0);
                    draw_circle(300+c,675,l);
                }

                glColor3f(1.0,1.0,1.0);
                glBegin(GL_TRIANGLES);
                    glVertex3f(200+c,675,0);
                    glVertex3f(300+c,682,0);
                    glVertex3f(300+c,668,0);
                glEnd();
            }

            //Plane
            if(plane==1)
            {
                for(l=0;l<=1;l++)
                {
                    glColor3f(1.0,0.0,0.0);
                    draw_circle(950+n,625+o,l);
                    glColor3f(1.0,1.0,0.0);
                    draw_circle(954+n,623+o,l);
                }
            }

            //grass
            glColor3f(0.0,1,0.0);
            glBegin(GL_POLYGON);
                glVertex3f(0,160,0);
                glVertex3f(0,450,0);
                glVertex3f(1100,450,0);
                glVertex3f(1100,160,0);
            glEnd();

            //pond
            glColor3f(0.0,0.0,0.4);
            glBegin(GL_POLYGON);
                glVertex3f(25,350,0);
                glVertex3f(25,375,0);
                glVertex3f(50,400,0);
                glVertex3f(75,410,0);
                glVertex3f(100,420,0);
                glVertex3f(200,420,0);
                glVertex3f(225,410,0);
                glVertex3f(250,405,0);
                glVertex3f(275,390,0);
                glVertex3f(300,375,0);
                glVertex3f(310,350,0);
                glVertex3f(300,320,0);
                glVertex3f(275,300,0);
                glVertex3f(250,295,0);
                glVertex3f(225,290,0);
                glVertex3f(200,285,0);
                glVertex3f(175,280,0);
                glVertex3f(150,280,0);
                glVertex3f(125,280,0);
                glVertex3f(100,290,0);
                glVertex3f(75,300,0);
                glVertex3f(50,310,0);
            glEnd();
        }

        //road boundary
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glVertex3f(0,150,0);
            glVertex3f(0,160,0);
            glVertex3f(1100,160,0);
            glVertex3f(1100,150,0);
        glEnd();

        //road
        glColor3f(0.2,0.2,0.2);
        glBegin(GL_POLYGON);
            glVertex3f(0,0,0);
            glVertex3f(0,150,0);
            glVertex3f(1100,150,0);
            glVertex3f(1100,0,0);
        glEnd();

        //road_divider

        glColor3f(1,1,0);
        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(0,70,0);
            glVertex3f(0,75,0);
            glVertex3f(100,75,0);
            glVertex3f(100,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        //glColor3f(1,1,0);
        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(150,70,0);
            glVertex3f(150,75,0);
            glVertex3f(210,75,0);
            glVertex3f(210,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(260,70,0);
            glVertex3f(260,75,0);
            glVertex3f(320,75,0);
            glVertex3f(320,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(370,70,0);
            glVertex3f(370,75,0);
            glVertex3f(430,75,0);
            glVertex3f(430,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(480,70,0);
            glVertex3f(480,75,0);
            glVertex3f(540,75,0);
            glVertex3f(540,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(590,70,0);
            glVertex3f(590,75,0);
            glVertex3f(650,75,0);
            glVertex3f(650,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(700,70,0);
            glVertex3f(700,75,0);
            glVertex3f(760,75,0);
            glVertex3f(760,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(810,70,0);
            glVertex3f(810,75,0);
            glVertex3f(870,75,0);
            glVertex3f(870,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(920,70,0);
            glVertex3f(920,75,0);
            glVertex3f(980,75,0);
            glVertex3f(980,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glVertex3f(1030,70,0);
            glVertex3f(1030,75,0);
            glVertex3f(1100,75,0);
            glVertex3f(1100,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        //zebra Crossing
        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glColor3f(1,1,1);
            glVertex3f(810,120,0);
            glVertex3f(810,150,0);
            glVertex3f(910,150,0);
            glVertex3f(910,120,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glColor3f(1,1,1);
            glVertex3f(810,0,0);
            glVertex3f(810,20,0);
            glVertex3f(910,20,0);
            glVertex3f(910,0,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glColor3f(1,1,1);
            glVertex3f(810,30,0);
            glVertex3f(810,50,0);
            glVertex3f(910,50,0);
            glVertex3f(910,30,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glColor3f(1,1,1);
            glVertex3f(810,60,0);
            glVertex3f(810,80,0);
            glVertex3f(910,80,0);
            glVertex3f(910,60,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glColor3f(1,1,1);
            glVertex3f(810,90,0);
            glVertex3f(810,110,0);
            glVertex3f(910,110,0);
            glVertex3f(910,90,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        //glBegin(GL_POLYGON);
        //glLoadIdentity();
          //  glColor3f(1,1,1);
          //  glVertex3f(810,90,0);
          //  glVertex3f(810,100,0);
           // glVertex3f(910,100,0);
          //  glVertex3f(910,90,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        //glEnd();

        //glBegin(GL_POLYGON);
        //glLoadIdentity();
         //   glColor3f(1,1,1);
         //   glVertex3f(810,70,0);
          //  glVertex3f(810,90,0);
          //  glVertex3f(910,90,0);
          //  glVertex3f(910,70,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        //glEnd();

        //passenger rest bench



        glBegin(GL_POLYGON);
        //glLoadIdentity();
            glColor3f(1,1,1);
            glVertex3f(650,250,0);
            glVertex3f(650,300,200);
            glVertex3f(900,300,200);
            glVertex3f(900,250,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
        glEnd();

        //tree
        glColor3f(0.9,0.2,0.0);
        glBegin(GL_POLYGON);
            glVertex3f(350,325,0);
            glVertex3f(350,395,0);
            glVertex3f(365,395,0);
            glVertex3f(365,325,0);
        glEnd();

        for(l=0;l<=30;l++)
        {
            glColor3f(0.0,0.5,0.0);
            draw_circle(340,400,l);
            draw_circle(380,400,l);
        }

        for(l=0;l<=25;l++)
        {
            glColor3f(0.0,0.5,0.0);
            draw_circle(350,440,l);
            draw_circle(370,440,l);
        }

        for(l=0;l<=20;l++)
        {
            glColor3f(0.0,0.5,0.0);
            draw_circle(360,465,l);
        }


        //passenger rest back
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
//            glVertex3f(650,375,0);
//            glVertex3f(700,425,0);
//            glVertex3f(925,425,0);
//            glVertex3f(950,375,0);

            glVertex3f(650,300,0);
            glVertex3f(700,375,0);
            glVertex3f(925,375,0);
            glVertex3f(950,300,0);
        glEnd();

        //passenger rest front
        glColor3f(0.7,0.7,0.7);
        glBegin(GL_POLYGON);
//            glVertex3f(650,325,0);
//            glVertex3f(650,375,0);
//            glVertex3f(950,375,0);
//            glVertex3f(950,325,0);

            glVertex3f(650,275,0);
            glVertex3f(650,300,0);
            glVertex3f(950,300,0);
            glVertex3f(950,275,0);
        glEnd();


        //passenger_rest
        {
            //glBegin(GL_POLYGON);
             //   glColor3f(1.0,1.0,0.0);
              //  glVertex3f(650,450,0);
              //  glVertex3f(950,450,0);
              //  glVertex3f(950,300,0);
              //  glVertex3f(650,300,0);
            //glEnd();

            //glBegin(GL_POLYGON);
        //glLoadIdentity();
          //  glColor3f(1,1,1);
          //  glVertex3f(650,250,0);
           // glVertex3f(650,300,0);
           // glVertex3f(900,300,0);
           // glVertex3f(900,250,0);
            //glPushMatrix();
            //glTranslatef(110,70,0);
            //glPopMatrix();
       // glEnd();
        }


                //void womand()
        {

            //face
            glColor3f(0,0,0);
            glPushMatrix();
            glTranslatef(540,495-175,0);
            glutSolidTorus(1,10,100,90);
            glPopMatrix();
            glColor3f(255,191,128);
            glPushMatrix();
            glTranslatef(540,494-175,0);
            glutSolidTorus(7,7,100,90);
            glPopMatrix();
            glColor3f(0,0,0);
            glBegin(GL_LINES);
                glVertex3f(540,494-175,0);
                glVertex3f(540,490-175,0); //nose
                glVertex3f(531,498-175,0);
                glVertex3f(532,499-175,0);
                glVertex3f(532,499-175,0);
                glVertex3f(537,498-175,0);//eyebrow
                glVertex3f(549,498-175,0);
                glVertex3f(548,499-175,0);
                glVertex3f(548,499-175,0);
                glVertex3f(543,498-175,0);//eyebrow
            glEnd();

            //ear right
            glBegin(GL_POLYGON);
                glColor3f(1,0,1);
                glVertex3f(540-14,494+1-175,0);
                glVertex3f(540-14,490+1-175,0);
                glVertex3f(538-14,489+1-175,0);
                glVertex3f(538-14,495+1-175,0);
            glEnd();
            //ear left
            glBegin(GL_POLYGON);
            glColor3f(1,0,1);
                glVertex3f(554,495-175,0);
                glVertex3f(556,496-175,0);
                glVertex3f(556,491-175,0);
                glVertex3f(554,490-175,0);
            glEnd();
                //ear ring right
            glBegin(GL_POLYGON);
            //glColor3f(255,85,90);
                glColor3f(1,0,0);
                glVertex3f(539-14,492-175,0);
                glVertex3f(542-14,485-175,0);
                glVertex3f(536-14,485-175,0);
            glEnd();
            //ear ring left
            glBegin(GL_POLYGON);
            //glColor3f(255,85,90);
                glColor3f(1,0,0);
                glVertex3f(551,485-175,0);
                glVertex3f(555,492-175,0);
                glVertex3f(558,485-175,0);
            glEnd();
            //hair
            glBegin(GL_POLYGON);
            //glColor3f(0,0,0);
                glColor3f(0,0,0);
                glVertex3f(525,499-175,0);
                glVertex3f(549,509-175,0);
                glVertex3f(540,512-175,0);
                glVertex3f(528,507-175,0);
            glEnd();
            glBegin(GL_POLYGON);
            //glColor3f(0,0,0);
                glColor3f(0,0,0);
                glVertex3f(540,507-175,0);
                glVertex3f(549,509-175,0);
                glVertex3f(552,507-175,0);
                glVertex3f(555,499-175,0);
            glEnd();
            // eyes
                glBegin(GL_POLYGON);
                glVertex3f(533,496-175,0);
                glVertex3f(535,496-175,0);
                glVertex3f(535,494-175,0);
                glVertex3f(533,494-175,0);
            glEnd();
            glBegin(GL_POLYGON);
                glVertex3f(545,496-175,0);
                glVertex3f(547,496-175,0);
                glVertex3f(547,496-175,0);
                glVertex3f(547,494-175,0);
                glVertex3f(545,494-175,0);
            glEnd();
            //mouth
            glBegin(GL_POLYGON);
                glColor3f(1,0,1);
                glVertex3f(534,487-175,0);
                glVertex3f(540,484-175,0);
                glVertex3f(546,487-175,0);
                glVertex3f(540,485-175,0);
            glEnd();
            //shirt
            glBegin(GL_POLYGON);
                glColor3f(1,1,20);
                glVertex3f(529,480-175,0);
                glVertex3f(551,480-175,0);
                glVertex3f(566,469-175,0);
                glVertex3f(561,460-175,0);
                glVertex3f(556,465-175,0);
                glVertex3f(556,445-175,0);
                glVertex3f(524,445-175,0);
                glVertex3f(524,465-175,0);
                glVertex3f(519,460-175,0);
                glVertex3f(514,469-175,0);
            glEnd();
            //neck
            glBegin(GL_POLYGON);
                glColor3f(1,0,1);
                glVertex3f(533,480-175,0);
                glVertex3f(547,480-175,0);
                glVertex3f(545,471-175,0);
                glVertex3f(535,471-175,0);
            glEnd();
            //hands
            glBegin(GL_POLYGON);
                glColor3f(1,0,1);
                glVertex3f(565,468-175,0);
                glVertex3f(575,453-175,0);
                glVertex3f(567,454-175,0);
                glVertex3f(562,462-175,0);
            glEnd();
            glBegin(GL_POLYGON);
                glVertex3f(575,453-175,0);
                glVertex3f(556,438-175,0);
                glVertex3f(556,445-175,0);
                glVertex3f(567,454-175,0);
            glEnd();
            glBegin(GL_POLYGON);
                glVertex3f(515,468-175,0);
                glVertex3f(505,453-175,0);
                glVertex3f(513,454-175,0);
                glVertex3f(518,462-175,0);
            glEnd();
            glBegin(GL_POLYGON);
                glVertex3f(505,453-175,0);
                glVertex3f(524,438-175,0);
                glVertex3f(524,445-175,0);
                glVertex3f(513,454-175,0);
            glEnd();
            // belt
            glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3f(556,445-175,0);
                glVertex3f(524,445-175,0);
                glVertex3f(524,440-175,0);
                glVertex3f(556,440-175,0);
            glEnd();


            // leg
            glBegin(GL_POLYGON);
                glColor3f(1,0,1);
                glVertex3f(555,440-175,0);
                glVertex3f(525,440-175,0);
                glVertex3f(520,405-175,0);
                glVertex3f(530,405-175,0);
                glVertex3f(533,438-175,0);
                glVertex3f(550,405-175,0);
                glVertex3f(560,405-175,0);
            glEnd();
            //skirt
            glBegin(GL_POLYGON);
                glColor3f(0,0,1);
                glVertex3f(524,440-175,0);
                glVertex3f(556,440-175,0);
                glVertex3f(566,410-175,0);
                glVertex3f(514,410-175,0);
            glEnd();
            //shoe left
            glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3f(530,405-175,0);
                glVertex3f(530,396-175,0);
                glVertex3f(528,396-175,0);
                glVertex3f(528,404-175,0);
                glVertex3f(522,396-175,0);
                glVertex3f(512,396-175,0);
                glVertex3f(520,405-175,0);
            glEnd();
            //shoe right
            glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3f(550,405-175,0);
                glVertex3f(550,396-175,0);
                glVertex3f(552,396-175,0);
                glVertex3f(552,404-175,0);
                glVertex3f(558,396-175,0);
                glVertex3f(568,396-175,0);
                glVertex3f(560,405-175,0);
            glEnd();

        }

        //signal
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
            glVertex3f(1060,160,0);
            glVertex3f(1060,350,0);
            glVertex3f(1070,350,0);
            glVertex3f(1070,160,0);
        glEnd();


        glColor3f(0.7,0.7,0.7);
        glBegin(GL_POLYGON);
            glVertex3f(1040,350,0);
            glVertex3f(1040,500,0);
            glVertex3f(1090,500,0);
            glVertex3f(1090,350,0);
        glEnd();

        for(l=0;l<=20;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1065,475,l);
            glColor3f(1.0,1.0,0.0);
            draw_circle(1065,425,l);
            glColor3f(0.0,0.0,0.0);
            draw_circle(1065,375,l);
        }

        //car 1
        glColor3f(0.9,0.2,0.0);
        glBegin(GL_POLYGON);
            glVertex3f(25+i,50,0);
            glVertex3f(25+i,125,0);
            glVertex3f(75+i,200,0);
            glVertex3f(175+i,200,0);
            glVertex3f(200+i,125,0);
            glVertex3f(250+i,115,0);
            glVertex3f(250+i,50,0);
        glEnd();


        //windows
        glColor3f(0.1,0.1,0.1);
        glBegin(GL_POLYGON);
            glVertex3f(35+i,125,0);
            glVertex3f(80+i,190,0);
            glVertex3f(115+i,190,0);
            glVertex3f(115+i,125,0);
        glEnd();

        glColor3f(0.1,0.1,0.1);
        glBegin(GL_POLYGON);
            glVertex3f(125+i,125,0);
            glVertex3f(125+i,190,0);
            glVertex3f(170+i,190,0);
            glVertex3f(190+i,125,0);
        glEnd();

        for(l=0;l<20;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(75+i,50,l);
            draw_circle(175+i,50,l);
        }

        //car2
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_POLYGON);
            glVertex3f(-470+i,50,0);
            glVertex3f(-470+i,112,0);
            glVertex3f(-400+i,125,0);
            glVertex3f(-372+i,210,0);
            glVertex3f(-210+i,210,0);
            glVertex3f(-180+i,125,0);
            glVertex3f(-135+i,125,0);
            glVertex3f(-110+i,50,0);
        glEnd();

        //windows
        glColor3f(0.1,0.1,0.1);
        glBegin(GL_POLYGON);
            glVertex3f(-410+i,125,0);
            glVertex3f(-364+i,200,0);
            glVertex3f(-300+i,200,0);
            glVertex3f(-300+i,125,0);
        glEnd();

        glColor3f(0.1,0.1,0.1);
        glBegin(GL_POLYGON);
            glVertex3f(-290+i,125,0);
            glVertex3f(-290+i,200,0);
            glVertex3f(-217+i,200,0);
            glVertex3f(-192+i,125,0);
        glEnd();


        for(l=0;l<30;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(-350+i,50,l);
            draw_circle(-200+i,50,l);
        }

        //bus
        glColor3f(0.7,0.0,0.9);
        glBegin(GL_POLYGON);
            glVertex3f(350+i,50,0);
            glVertex3f(350+i,275,0);
            glVertex3f(722+i,275,0);
            glVertex3f(750+i,175,0);
            glVertex3f(750+i,50,0);
        glEnd();



        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glVertex3f(650+i,175,0);
            glVertex3f(650+i,260,0);
            glVertex3f(720+i,260,0);
            glVertex3f(745+i,175,0);
        glEnd();



        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glVertex3f(550+i,175,0);
            glVertex3f(550+i,260,0);
            glVertex3f(625+i,260,0);
            glVertex3f(625+i,175,0);
        glEnd();


        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glVertex3f(450+i,175,0);
            glVertex3f(450+i,260,0);
            glVertex3f(525+i,260,0);
            glVertex3f(525+i,175,0);
        glEnd();


        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glVertex3f(375+i,175,0);
            glVertex3f(375+i,260,0);
            glVertex3f(425+i,260,0);
            glVertex3f(425+i,175,0);
        glEnd();

        for(l=0;l<30;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(450+i,50,l);
            draw_circle(625+i,50,l);
        }
        glFlush();
    }
    void traffic_light()
    {
        int l;
        if(light==1)
        {
            for(l=0;l<=20;l++)
            {
                glColor3f(0.0,0.0,0.0);
                draw_circle(1065,475,l);

                //glColor3f(1.0,1.0,0.0);
                //draw_circle(1065,425,l);

                glColor3f(0.0,1.0,0.0);
                draw_circle(1065,375,l);
            }
        }

        else
        {
            for(l=0;l<=20;l++)
            {
                glColor3f(1.0,0.0,0.0);
                draw_circle(1065,475,l);

                //glColor3f(0.0,0.0,0.0);
                //draw_circle(1065,425,l);

                glColor3f(0.0,0.0,0.0);
                draw_circle(1065,375,l);
            }
        }
    }
    void idle()
    {
        glClearColor(1.0,1.0,1.0,1.0);
        if(light==0 && (i>=330 && i<=750)) //value of i when first vehicle is near the traffic-signal
        {
            i+=SPEED/10;
            ++m;
            n-=2;
            o+=0.2;
            c+=2;
        }

        if(light==0 && (i>=830 && i<=1100)) //value of i when second vehicle is near the traffic-signal
        {
            i+=SPEED/10;
            ++m;
            n-=2;
            o+=0.2;
            c+=2;
        }
        if(light==0 && (i>=1200 && i<=1620))// value of i when third vehicle is near the traffic signal
        {
            i+=SPEED/10;
            ++m;
            n-=2;
            o+=0.2;
            c+=2;
        }

        if(light==0)
        {
            i=i;
            ++m;
            n-=2;
            o+=0.2;
            c+=2;
        }
        else
        {
            i+=SPEED/10;
            ++m;
            n-=2;
            o+=0.2;
            c+=2;
        }
        if(i>1630)
            i=0.0;
        if(m>1100)
            m=0.0;
        if( o>75)
        {
            plane=0;
        }
        if(c>500)
        {
            comet=0;
        }
        glutPostRedisplay();

    }

    void mouse(int btn,int state,int x,int y)
    {
        if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        exit(0);
    }

    void keyboardFunc( unsigned char key, int x, int y )
    {
        switch( key )
        {
            case 'g':
            case 'G':
                light=1;
                break;
            case 'r':
            case 'R':
                light=0;
                break;

            case 'd':
            case 'D':
                day=1;
                break;

            case 'n':
            case 'N':
                day=0;
                break;
        };
    }
    void main_menu(int index)
    {
        switch(index)
        {
            case 1:
            if(index==1)
            {
                plane=1;
                o=n=0.0;
            }
            break;

            case 2:
            if(index==2)
            {
                comet=1;
                c=0.0;
            }
            break;
        }
    }
    void myinit()
    {
        glClearColor(1.0,1.0,1.0,1.0);
        glColor3f(0.0,0.0,1.0);
        glPointSize(2.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,1100.0,0.0,700.0);
    }
    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        draw_object();
        traffic_light();
        glFlush();
    }
    int main(int argc,char** argv)
    {
        int c_menu;
        printf("Press 'r' or 'R' to change the signal light to red \n");
        printf("Press 'g' or 'G' to change the signal light to green \n");

        printf("Press 'd' or 'D' to make it day \n");
        printf("Press 'n' or 'N' to make it night \n");

        printf("Press RIGHT MOUSE BUTTON to display menu \n");
        printf("Press LEFT MOUSE BUTTON to quit the program \n");

        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(1100.0,700.0);
        glutInitWindowPosition(0,0);
        glutCreateWindow("BUS STOP.COMPUTER GRAPHICS PROJECT");
        glutDisplayFunc(display);
        glutIdleFunc(idle);
        glutKeyboardFunc(keyboardFunc);
        glutMouseFunc(mouse);
        myinit();


        c_menu=glutCreateMenu(main_menu);
        glutAddMenuEntry("Aeroplane",1);
        glutAddMenuEntry("Comet",2);
        glutAttachMenu(GLUT_RIGHT_BUTTON);


        glutMainLoop();
        return 0;
    }


