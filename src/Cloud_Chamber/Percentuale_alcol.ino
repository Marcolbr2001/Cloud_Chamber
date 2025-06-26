void percentualealcol()
{

  posmenu=false;
  int a;
  int aprec=0;
  int y1, y2;
  int x1, x2;
  float passo=lungGrafA/(CA-1.0);

  //Inizializzazione 
  tft.fillScreen(White);
  tft.setFont();
  tft.setTextColor(Black);

  
  //Diagramma cartesiano
  tft.drawFastHLine(X0A-20,Y0A,lungGrafA+20,Black);
  tft.drawFastHLine(X0A-20,Y0A+epsilon,lungGrafA+20,Black);tft.drawFastHLine(X0A-20,Y0A+2*epsilon,lungGrafA+20,Black);tft.drawFastHLine(X0A-20,Y0A-epsilon,lungGrafA+20,Black);tft.drawFastHLine(X0A-20,Y0A-2*epsilon,lungGrafA+20,Black);
  tft.drawFastVLine(X0A,Y0A-altGrafA,altGrafA+20,Black);
  tft.drawFastVLine(X0A+epsilon,Y0A-altGrafA,altGrafA+20,Black);tft.drawFastVLine(X0A+2*epsilon,Y0A-altGrafA,altGrafA+20,Black);tft.drawFastVLine(X0A-epsilon,Y0A-altGrafA,altGrafA+20,Black);tft.drawFastVLine(X0A-2*epsilon,Y0A-altGrafA,altGrafA+20,Black);
  //Valori sugli assi
  tft.setTextSize(2);
  tft.setTextColor(Black);
  tft.setCursor(X0A-50,Y0A-255);
  tft.print("%");
  tft.setCursor(X0A+170,Y0A+10);
  tft.print("t(s)");
  tft.setTextSize(1);
  tft.setCursor(X0A-27,Y0A-(altGrafA*10/10+3));
  tft.print("100-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*9/10+3));
  tft.print("90-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*8/10+3));
  tft.print("80-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*7/10+3));
  tft.print("70-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*6/10+3));
  tft.print("60-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*5/10+3));
  tft.print("50-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*4/10+3));
  tft.print("40-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*3/10+3));
  tft.print("30-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*2/10+3));
  tft.print("20-");
  tft.setCursor(X0A-20,Y0A-(altGrafA*1/10+3));
  tft.print("10-");
  //Linee in mezzo al grafico
  tft.drawFastHLine(X0A,Y0A-(altGrafA*1/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*2/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*3/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*4/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*5/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*6/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*7/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*8/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*9/10),lungGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(altGrafA*10/10),lungGrafA,colorLineValGraf);
  tft.drawFastVLine(X0A+lungGrafA,Y0A-altGrafA,altGrafA,colorLineValGraf);
  tft.drawFastHLine(X0A,Y0A-(val_ott*altGrafA/100),lungGrafA,colorvalottgafLine);

  //disegno grafico acquisito precedentemente
  for(int in=1;in<contvAl;in++)
  {
    tft.drawLine(passo*in+X0A,Y0A-(float)(((float)((graficoAl[in])*altGrafA)/100)),passo*in+X0A-passo,Y0A-(float)(((float)((graficoAl[in-1])*altGrafA)/100)),colorGrafAl);
  }
  

  ///Disegno corona circolare
  tft.fillCircle(CccAX,CccAY,ReccA,colorSfondoDisAl);
  tft.fillCircle(CccAX,CccAY,RiccA,colorCenterA);
  tft.drawLine((ReccA * (cos(PI * val_ott*20 / 1000)))+CccAX,(ReccA * (sin(PI * val_ott*20 / 1000)))+CccAY,((RiccA+2) * (cos(PI * val_ott*20 / 1000)))+CccAX,((RiccA+2) * (sin(PI * val_ott*20 / 1000)))+CccAY,colorvalottLine);
  tft.drawLine((ReccA * (cos(PI * (val_ott*20+1) / 1000)))+CccAX,(ReccA * (sin(PI * (val_ott*20+1) / 1000)))+CccAY,((RiccA+2) * (cos(PI * (val_ott*20+1) / 1000)))+CccAX,((RiccA+2) * (sin(PI * (val_ott*20+1) / 1000)))+CccAY,colorvalottLine);
  tft.drawLine((ReccA * (cos(PI * (val_ott*20-1) / 1000)))+CccAX,(ReccA * (sin(PI * (val_ott*20-1) / 1000)))+CccAY,((RiccA+2) * (cos(PI * (val_ott*20-1) / 1000)))+CccAX,((RiccA+2) * (sin(PI * (val_ott*20-1) / 1000)))+CccAY,colorvalottLine);
  tft.drawLine((ReccA * (cos(PI * (val_ott*20+2) / 1000)))+CccAX,(ReccA * (sin(PI * (val_ott*20+2) / 1000)))+CccAY,((RiccA+2) * (cos(PI * (val_ott*20+2) / 1000)))+CccAX,((RiccA+2) * (sin(PI * (val_ott*20+2) / 1000)))+CccAY,colorvalottLine);
  tft.drawLine((ReccA * (cos(PI * (val_ott*20-2) / 1000)))+CccAX,(ReccA * (sin(PI * (val_ott*20-2) / 1000)))+CccAY,((RiccA+2) * (cos(PI * (val_ott*20-2) / 1000)))+CccAX,((RiccA+2) * (sin(PI * (val_ott*20-2) / 1000)))+CccAY,colorvalottLine);

  tft.setTextSize(5);
  tft.setCursor(CccAX+50,CccAY-18);
  tft.print("%");


  randomSeed(millis());
  
  
  do
  {
    //uscita dal ciclo
    if(Back)
    {
      Back=false;
      break;
    }
    //contollo dei valori
    control();
    tft.setTextColor(Black);
    tft.setTextSize(5);
    value = digitalReadAlcol;//Leggi il valore del pin analogico A0, è il valore dell'alcool nell'ambiente

    //a=value*2000/100;
    a=value*20;
    /*
    value= analogRead(AOUTpin);//Leggi il valore del pin analogico A0, è il valore dell'alcool nell'ambiente
    //a=conversione di value in scala 2000//a deve essere "tarato" su 2000
    limit= digitalRead(DOUTpin);//Leggi il valore del pin digitale D8 (non ho ancora capito bene a cosa serva)
    */
    

    ///AGGIORNAMENTO GRAFICO
    if(a>aprec)//Aggiornamento in positivo
    {
      tft.setCursor(CccAX-72,CccAY-18);
      tft.fillRect(CccAX-72,CccAY-18,120,40,colorCenterA);
      if(value<10)
      {
        tft.print(" ");
      }
      tft.print(value,1); 
      
      for(int in=aprec;in<a;in++)
      {
        y1 = ReccA * (sin(PI * in / 1000));
        x1 = ReccA * (cos(PI * in / 1000));
        y2 = (RiccA+2) * (sin(PI * in / 1000));
        x2 = (RiccA+2) * (cos(PI * in / 1000));
        if(in<((val_ott-erassol)*20))
          tft.drawLine(x2 + CccAX, y2 + CccAY, x1 + CccAX, y1 + CccAY, colorminvalott);
        if(in<=((val_ott+erassol)*20)&&in>=((val_ott-erassol)*20)&&in!=(val_ott*20)&&in!=((val_ott*20)+1)&&in!=((val_ott*20)-1)&&in!=((val_ott*20)+2)&&in!=((val_ott*20)-2)&&in!=((val_ott*20)+3)&&in!=((val_ott*20)-3)&&in!=((val_ott*20)+4)&&in!=((val_ott*20)-4)&&in!=((val_ott*20)+5)&&in!=((val_ott*20)-5)&&in!=((val_ott*20)+6)&&in!=((val_ott*20)-6)&&in!=((val_ott*20)+7)&&in!=((val_ott*20)-7))
          tft.drawLine(x2 + CccAX, y2 + CccAY, x1 + CccAX, y1 + CccAY, colorvalott);
        if(in>((val_ott+erassol)*20))
          tft.drawLine(x2 + CccAX, y2 + CccAY, x1 + CccAX, y1 + CccAY, colormaggvalott);
      }
      
      
    }
    if (a<aprec)//Aggiornamento in negativo
    {
      tft.setCursor(CccAX-72,CccAY-18);
      tft.fillRect(CccAX-72,CccAY-18,120,40,colorCenterA);
      if(value<10)
      {
        tft.print(" ");
      }
      tft.print(value,1); 
      
      for(int in=aprec;in>a;in--)
      {
        y1 = ReccA * (sin(PI * in / 1000));
        x1 = ReccA * (cos(PI * in / 1000));
        y2 = (RiccA+2) * (sin(PI * in / 1000));
        x2 = (RiccA+2) * (cos(PI * in / 1000));
        if(in!=(val_ott*20)&&in!=((val_ott*20)+1)&&in!=((val_ott*20)-1)&&in!=((val_ott*20)+2)&&in!=((val_ott*20)-2)&&in!=((val_ott*20)+3)&&in!=((val_ott*20)-3)&&in!=((val_ott*20)+4)&&in!=((val_ott*20)-4)&&in!=((val_ott*20)+5)&&in!=((val_ott*20)-5)&&in!=((val_ott*20)+6)&&in!=((val_ott*20)-6)&&in!=((val_ott*20)+7)&&in!=((val_ott*20)-7))
          tft.drawLine(x2 + CccAX, y2 + CccAY, x1 + CccAX, y1 + CccAY, colorSfondoDisAl);
        
      }
    }

    aprec=a;

    

    //aggiornamento del grafico

    if (contAl==0)
    {
      ///GRAFICO
      
      if(contvAl<CA)
      {
        tft.drawLine(passo*(contvAl-1)+X0A,Y0A-(float)(((float)((graficoAl[contvAl-1])*altGrafA)/100.0)),passo*(contvAl-2)+X0A,Y0A-(float)(((float)((graficoAl[contvAl-2])*altGrafA)/100.0)),colorGrafAl);

      }
      else
      {
        
        tft.fillRect(X0A+2*epsilon,Y0A-altGrafA-2*epsilon,lungGrafA,altGrafA,White);
        tft.drawFastVLine(X0A,Y0A-altGrafA,altGrafA,Black);tft.drawFastVLine(X0A+epsilon,Y0A-altGrafA,altGrafA,Black);tft.drawFastVLine(X0A+2*epsilon,Y0A-altGrafA,altGrafA,Black);
        tft.drawFastHLine(X0A,Y0A,lungGrafA,Black);tft.drawFastHLine(X0A,Y0A-epsilon,lungGrafA,Black);tft.drawFastHLine(X0A,Y0A-2*epsilon,lungGrafA,Black);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*1/100),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*2/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*3/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*4/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*5/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*6/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*7/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*8/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*9/10),lungGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(altGrafA*10/10),lungGrafA,colorLineValGraf);
        tft.drawFastVLine(X0A+lungGrafA,Y0A-altGrafA,altGrafA,colorLineValGraf);
        tft.drawFastHLine(X0A,Y0A-(val_ott*altGrafA/100),lungGrafA,colorvalottgafLine);

        for(int in=1;in<CA;in++)
        {
          
          tft.drawLine(passo*in+X0A,Y0A-(float)(((float)((graficoAl[in])*altGrafA)/100)),passo*in+X0A-passo,Y0A-(float)(((float)((graficoAl[in-1])*altGrafA)/100)),colorGrafAl);
        }
      }
      
    }


    


  }while(1);
  drawMainMenu(); 

}
