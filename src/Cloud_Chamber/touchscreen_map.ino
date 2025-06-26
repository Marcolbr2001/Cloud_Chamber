void touchmap()
{
  if(posmenu)
  {
  TSPoint p=ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
 
  if(p.z>MINPRESSURE&&p.z<MAXPRESSURE)
  {
    
    xpos = map(p.x, TS_LEFT, TS_RT, 0, tft.width());
    ypos = map(p.y, TS_TOP, TS_BOT, 0, tft.height());

    //alcol
    if(xpos>=0 && xpos<=480 && ypos>=0 && ypos<=64.8)
      Menu=1;

    //piastra nera  
    if(xpos>=19.2 && xpos<=460.8 && ypos>=64.8 && ypos<=100)
      Menu=2;
    
    //prima peltier
    if(xpos>=36.8 && xpos<=126.4 && ypos>100 && ypos<=141.6)
      Menu=3;
      
    //seconda peltier
    if(xpos>=142.4 && xpos<=232 && ypos>100 && ypos<=141.6)
      Menu=4;
       
    //terza peltier 
    if(xpos>=248 && xpos<=337.6 && ypos>100 && ypos<=141.6)
      Menu=5;
       

    //quarta peltier 
    if(xpos>=353.6 && xpos<=443.2 && ypos>100 && ypos<=141.6)
      Menu=6;
     

    //Rame1
   if(xpos>=19.2 && xpos<=460.8 && ypos>=141.6 && ypos<=183.2)
      Menu=7;
      
    //Peltierona
   if(xpos>=104 && xpos<=376 &&ypos>=182 && ypos<=231.2)
      Menu=8;
      
    
     //Rame2
    if(xpos>=19.2 && xpos<=460.8 && ypos>=231.6 && ypos<=273.2)
      Menu=9;

    
     //Acqua
    if(xpos>=19.2 && xpos<=460.8 && ypos>=266.8 && ypos<=320)
      Menu=10;

    //GRAFICO TEMPERATURA TOTALE
    if(xpos>=425&&xpos<=472&&ypos>=183&&ypos<=230)
      Menu=11;

    //INVERSIONE CAMPO ELETTRICO
    if(xpos>=8&&xpos<=55&&ypos>=183&&ypos<=230)
      Menu=12;
    //ACCENSIONE LED
    if(xpos>=373&&xpos<=420&&ypos>=183&&ypos<=230)
      Menu=13;
    if(xpos>=60&&xpos<=107&&ypos>=183&&ypos<=230)
      Menu=14;
  }
  }
  else
  {
    TSPoint p=ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    if(p.z>MINPRESSURE&&p.z<MAXPRESSURE)
    {
      xpos = map(p.x, TS_LEFT, TS_RT, 0, tft.width());
      ypos = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
      if(xpos>40&&xpos<90&&ypos>15&&ypos<65)
        Back=true;
    }
  }
}
