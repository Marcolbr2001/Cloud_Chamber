
void drawMainMenu()
{
  posmenu=true;
  senserprec=0;
  numerprec=0;
  ///Main Menu
  tft.setFont();
  tft.fillScreen(White);
  control();

  
  //aria
  tft.fillRect(0,0,480,64.8,coloraria);
tft.setTextSize(2);
  if(digitalReadAlcol>val_ott+erassol||digitalReadAlcol<val_ott-erassol)
  {
    tft.setTextColor(Red);
    tft.setCursor(260,25);
    tft.print("%");
    alcprec=true;
  }
  else
  {
    tft.setTextColor(Black);
    tft.setCursor(260,25);
    tft.print("%");
    alcprec=false;
  }

  tft.setCursor(199,25);
  if(digitalReadAlcol<99)
    tft.print(" ");
  if(digitalReadAlcol<10)
    tft.print(" ");  
  tft.print(digitalReadAlcol,1);

  //campo elettrico
  if(Electricfield)
  {
    tft.drawBitmap(40,10,uparrowimg,30,45,Black);
    tft.drawBitmap(100,10,uparrowimg,30,45,Black);
    tft.drawBitmap(160,10,uparrowimg,30,45,Black);
    tft.drawBitmap(290,10,uparrowimg,30,45,Black);
    tft.drawBitmap(350,10,uparrowimg,30,45,Black);
    tft.drawBitmap(410,10,uparrowimg,30,45,Black);
  }
  else
  {
    tft.drawBitmap(40,10,downarrowimg,30,45,Black);
    tft.drawBitmap(100,10,downarrowimg,30,45,Black);
    tft.drawBitmap(160,10,downarrowimg,30,45,Black);
    tft.drawBitmap(290,10,downarrowimg,30,45,Black);
    tft.drawBitmap(350,10,downarrowimg,30,45,Black);
    tft.drawBitmap(410,10,downarrowimg,30,45,Black);
  }
  
  
  

  
  //rame nero
  tft.fillRect(19.2,64.8,441.6,36.2,colorramner);
  tft.setTextSize(2);
  if(digitalRN)
  {
    tft.setTextColor(Red);
    tft.setCursor(210,75);
    tft.print("ERROR");
    funzrn=true;
  }
  else
  {
    if(funzrn)
    {
      funzrn=false;
    }
    if(digitalReadRameNero>val_ott_rn+errrn||digitalReadRameNero<val_ott_rn-errrn)
    {
      tft.setTextColor(Red);
      tft.setCursor(273,75);
      tft.print((char)167);
      tft.print("C");
      rnprec=true;
    }
    else
    {
      tft.setTextColor(White);
      tft.setCursor(273,75);
      tft.print((char)167);
      tft.print("C");
      rnprec=false;
    }
    tft.setCursor(200,75);
    if(digitalReadRameNero>-10)
      tft.print(" ");
    if(digitalReadRameNero>=0&&digitalReadRameNero<10)
      tft.print(" ");
    tft.print(digitalReadRameNero);
  }
  
  //prima peltier
  tft.setTextSize(2);
  if (pelt1acc)
  {
    tft.fillRect(36.8,100,89.6,41.6,colorpelt);
    tft.setCursor(70,113);
    tft.setTextColor(0x7E0);
    tft.print("ON");
  }
  else
  {
    tft.fillRect(36.8,100,89.6,41.6,colorpeloff);
    tft.setCursor(66,113);
    tft.setTextColor(0x0000);
    tft.print("OFF");
  }
  
  //seconda peltier
  tft.setTextSize(2);
  if(pelt2acc)
  {
    tft.fillRect(142.4,100,89.6,41.6,colorpelt);
    tft.setCursor(175.6,113);
    tft.setTextColor(0x7E0);
    tft.print("ON");
  }
    
  else
  {
    tft.fillRect(142.4,100,89.6,41.6,colorpeloff);
    tft.setCursor(171.6,113);
    tft.setTextColor(0x0000);
    tft.print("OFF");
  }
  
  //terza peltier
  tft.setTextSize(2);
  if(pelt3acc)
  {
    tft.fillRect(248,100,89.6,41.6,colorpelt);
    tft.setCursor(281.2,113);
    tft.setTextColor(0x7E0);
    tft.print("ON");
  }
  else
  {
    tft.fillRect(248,100,89.6,41.6,colorpeloff);
    tft.setCursor(277.2,113);
    tft.setTextColor(0x0000);
    tft.print("OFF");
  }

  
  //quarta peltier
  tft.setTextSize(2);
  if(pelt4acc)
  {
    tft.fillRect(353.6,100,89.6,41.6,colorpelt);
    tft.setCursor(386.8,113);
    tft.setTextColor(0x7E0);
    tft.print("ON");
  }
  else
  {
    tft.fillRect(353.6,100,89.6,41.6,colorpeloff);
    tft.setCursor(382.8,113);
    tft.setTextColor(0x0000);
    tft.print("OFF");
  }
  
  
  //rame 1
  tft.fillRect(19.2,141.6,441.6,41.6,colorram);
  tft.setTextSize(2);
  if(digitalR1)
  {
    tft.setTextColor(Red);
    tft.setCursor(210,154);
    tft.print("ERROR");
    funzr1=true;
  }
  else
  {
    if(funzr1)
    {
      funzr1=false;
    }
    if(digitalReadRame1>val_ott_r1+errr1||digitalReadRame1<val_ott_r1-errr1)
    {
      tft.setTextColor(Red);
      tft.setCursor(273,154);
      tft.print((char)167);
      tft.print("C"); 
      r1prec=true;
    }
    else
    {
      tft.setTextColor(White);
      tft.setCursor(273,154);
      tft.print((char)167);
      tft.print("C");
      r1prec=false;
    }

    tft.setCursor(200,154);
    if(digitalReadRame1>-10)
      tft.print(" ");
    if(digitalReadRame1>=0&&digitalReadRame1<10)
      tft.print(" ");
    tft.print(digitalReadRame1);
  }
  
  //Peltierona
  tft.setTextSize(2);
  if(peltonaacc)
  {
    tft.fillRect(104,182,272,49.2,colorpelt);
    tft.setCursor(227,198.8);
    tft.setTextColor(0x7E0);
    tft.print("ON");
  }
  else
  {
    tft.fillRect(104,182,272,49.2,colorpeloff);
    tft.setCursor(223,198.8);
    tft.setTextColor(0x0000);
    tft.print("OFF");
  }
  
  
  //rame 2
  tft.fillRect(19.2,231.6,441.6,41.6,colorram);
 tft.setTextSize(2);
  if(digitalR2)
  {
    tft.setTextColor(Red);
    tft.setCursor(210,242);
    tft.print("ERROR");
    funzr2=true;
  }
  else
  {
    if(funzr2)
    {
      funzr2=false;
    }
    if(digitalReadRame2>val_ott_r2+errr2||digitalReadRame2<val_ott_r2-errr2)
    {
      tft.setTextColor(Red);
      tft.setCursor(273,242);
      tft.print((char)167);
      tft.print("C");
      r2prec=true;
    }
    else
    {
      tft.setTextColor(White);
      tft.setCursor(273,242);
      tft.print((char)167);
      tft.print("C");
      r2prec=false;
    }
    tft.setCursor(200,242);
    if(digitalReadRame2>-10)
      tft.print(" ");
    if(digitalReadRame2>=0&&digitalReadRame2<10)
      tft.print(" ");
    tft.print(digitalReadRame2);
  }
  
  //acqua
  tft.fillRect(19.2,266.8,441.6,54.2,coloracq);
  tft.setTextSize(2);
  if(((digitalReadAcqua1+digitalReadAcqua2)/2)>val_ott_ac+errac||((digitalReadAcqua1+digitalReadAcqua2)/2)<val_ott_ac-errac)
  {
    tft.setTextColor(0xF800);
      tft.setCursor(273,288);
    tft.print((char)167);
    tft.print("C");
    acprec=true;
  }
  else
  {
    tft.setTextColor(0x0000);
      tft.setCursor(273,288);
    tft.print((char)167);
    tft.print("C");
    acprec=false;
  }

  tft.setCursor(200,288);
  tft.print(" ");
  if(((digitalReadAcqua1+digitalReadAcqua2)/2)<10)
    tft.print(" ");
  tft.print((digitalReadAcqua1+digitalReadAcqua2)/2);

  tft.drawBitmap(425,183,magnifier,47,47,Black);
  tft.drawBitmap(8,183,efiledimg,47,47,Black);

  if(led)
  {
    tft.drawBitmap(373,183,lampon,47,47,Black);
  }
  else
  {
    tft.drawBitmap(373,183,lampoff,47,47,Black);
  }
  




  touchmap();
  
}
