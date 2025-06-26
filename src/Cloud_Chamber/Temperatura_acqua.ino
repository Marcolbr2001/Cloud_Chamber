

void temperaturacqua()
{

  posmenu=false;
  int Tempprec1=0,Tempprec2=0;
  int h1,h2,hp1=-30,hp2=-30;
  float hgraftemp=80.0;
  float passo=lungGrafTA/(CTA-1.0);

  //Inizializzazione
  tft.setFont();
  tft.fillScreen(White);
  tft.setTextColor(Black);

  tft.drawBitmap(40,15,homeimg,50,50,Black);
  

  
  //Diagramma cartesiano
  tft.drawFastHLine(X0TA-20,Y0TA,lungGrafTA+20,Black);
  tft.drawFastHLine(X0TA-20,Y0TA+epsilon,lungGrafTA+20,Black);tft.drawFastHLine(X0TA-20,Y0TA+2*epsilon,lungGrafTA+20,Black);tft.drawFastHLine(X0TA-20,Y0TA-epsilon,lungGrafTA+20,Black);tft.drawFastHLine(X0TA-20,Y0TA-2*epsilon,lungGrafTA+20,Black);
  tft.drawFastVLine(X0TA,Y0TA-altGrafTA,altGrafTA+20,Black);
  tft.drawFastVLine(X0TA+epsilon,Y0TA-altGrafTA,altGrafTA+20,Black);tft.drawFastVLine(X0TA+2*epsilon,Y0TA-altGrafTA,altGrafTA+20,Black);tft.drawFastVLine(X0TA-epsilon,Y0TA-altGrafTA,altGrafTA+20,Black);tft.drawFastVLine(X0TA-2*epsilon,Y0TA-altGrafTA,altGrafTA+20,Black);
  //Scritte sugli assi
  tft.setTextSize(2);
  tft.setTextColor(Black);
  tft.setCursor(X0TA-85,Y0TA-235);
  tft.print("T(");
  tft.print((char)167);
  tft.print("C)");
  tft.setCursor(X0TA+170,Y0TA+10);
  tft.print("t(s)");
  tft.setTextSize(1);
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*8/8+3));
  tft.print("80-");
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*7/8+3));
  tft.print("70-");
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*6/8+3));
  tft.print("60-");
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*5/8+3));
  tft.print("50-");
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*4/8+3));
  tft.print("40-");
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*3/8+3));
  tft.print("30-");
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*2/8+3));
  tft.print("20-");
  tft.setCursor(X0TA-20,Y0TA-(altGrafTA*1/8+3));
  tft.print("10-");
  //Linee valori
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*1/8,lungGrafTA,colorLineValGraf);
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*2/8,lungGrafTA,colorLineValGraf);
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*3/8,lungGrafTA,colorLineValGraf);
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*4/8,lungGrafTA,colorLineValGraf);
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*5/8,lungGrafTA,colorLineValGraf);
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*6/8,lungGrafTA,colorLineValGraf);
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*7/8,lungGrafTA,colorLineValGraf);
  tft.drawFastHLine(X0TA,Y0TA-altGrafTA*8/8,lungGrafTA,colorLineValGraf);
  tft.drawFastVLine(X0TA+lungGrafTA,Y0TA-altGrafTA,altGrafTA,colorLineValGraf);

  //disegno grafico acquisito precedentemente
  for(int i=1;i<contvTA;i++)
  {
    tft.drawLine(passo*i+X0TA,Y0TA-(float)(((float)((graficoTA[i])*altGrafTA)/hgraftemp)),passo*i+X0TA-passo,Y0TA-(float)(((float)((graficoTA[i-1])*altGrafTA)/hgraftemp)),colorGrafA);
  }
  

  //Disegno dei Termometri
  tft.setTextSize(2);
  tft.setTextColor(Black);
  
  tft.fillCircle(59,230,30,Black);
  tft.fillRoundRect(49,80,24,133,12,Black);
  tft.fillCircle(59,230,22,colorTermA1);
  tft.setCursor(91,280);
  tft.print((char)167);
  tft.print("C");
  
  tft.fillCircle(150,230,30,Black);
  tft.fillRoundRect(140,80,24,133,12,Black);
  tft.fillCircle(150,230,22,colorTermA2);
  tft.setCursor(181,280);
  tft.print((char)167);
  tft.print("C");
 
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
    Temp1=digitalReadAcqua1;
    Temp2=digitalReadAcqua2;

    //AGGIORNAMENTO TERMOMETRO
    //Termometro 1
    if(Temp1>Tempprec1)//Aggiornamento in positivo
    {
      tft.fillRect(28,270,60,40,White);
      tft.setCursor(29,280);
      if(Temp1<10)
        tft.print(" ");
      tft.print((Temp1));

      h1=(Temp1-mintemp)*110/abs(mintemp-maxtemp);
      tft.fillRect(54,230-(h1+30),12,h1-hp1,colorTermA1); 
      hp1=h1;
    }
    if(Temp1<Tempprec1)//Aggiornamento in negativo
    {
      tft.fillRect(28,270,60,40,White);
      tft.setCursor(29,280);
      if(Temp1<10)
        tft.print(" ");
      tft.print((Temp1));

      h1=(Temp1-mintemp)*110/abs(mintemp-maxtemp);
      tft.fillRect(54,230-(hp1+30),12,hp1-h1,Black); 
      hp1=h1;
    }
    //Termometro 2
    if(Temp2>Tempprec2)//Aggiornamento in positivo
    {
      tft.fillRect(118,270,60,40,White);
      tft.setCursor(119,280);
      if(Temp2<10)
        tft.print(" ");
      tft.print((Temp2));

      h2=(Temp2-mintemp)*110/abs(mintemp-maxtemp);
      tft.fillRect(146,230-(h2+30),12,h2-hp2,colorTermA2); 
      hp2=h2;
    }
    if(Temp2<Tempprec2)//Aggiornamento in negativo
    {
      
      tft.fillRect(118,270,60,40,White);
      tft.setCursor(119,280);
      if(Temp2<10)
        tft.print(" ");
      tft.print((Temp2));

      h2=(Temp2-mintemp)*110/abs(mintemp-maxtemp);
      tft.fillRect(146,230-(hp2+30),12,hp2-h2,Black); 
      hp2=h2;
    }

    //Inizializzazione delle variabili precedenti per il confronto nel prossimo ciclo
    Tempprec1=Temp1;
    Tempprec2=Temp2;


    ///AGGIORNAMENTO GRAFICO
    if (contTA==0)//Inserire un solo valore ogni tot
    {
      
      if(contvTA<CTA)//fincè l'array non è al massimo inserisco valori e traccio la linea che li descrive
      {
        tft.drawLine(passo*(contvTA-1)+X0TA,Y0TA-(float)(((float)((graficoTA[contvTA-1])*altGrafTA)/hgraftemp)),passo*(contvTA-2)+X0TA,Y0TA-(float)(((float)((graficoTA[contvTA-2])*altGrafTA)/hgraftemp)),colorGrafA);
      }
      else
      {
        
        tft.fillRect(X0TA+2*epsilon,Y0TA-altGrafTA,lungGrafTA,altGrafTA-2*epsilon,White);
        
        tft.drawFastVLine(X0TA,Y0TA-altGrafTA,altGrafTA,Black);tft.drawFastVLine(X0TA+epsilon,Y0TA-altGrafTA,altGrafTA,Black);tft.drawFastVLine(X0TA+2*epsilon,Y0TA-altGrafTA,altGrafTA,Black);
        tft.drawFastHLine(X0TA,Y0TA,lungGrafTA,Black);tft.drawFastHLine(X0TA,Y0TA-epsilon,lungGrafTA,Black);tft.drawFastHLine(X0TA,Y0TA-2*epsilon,lungGrafTA,Black);
        
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*1/8,lungGrafTA,colorLineValGraf);
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*2/8,lungGrafTA,colorLineValGraf);
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*3/8,lungGrafTA,colorLineValGraf);
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*4/8,lungGrafTA,colorLineValGraf);
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*5/8,lungGrafTA,colorLineValGraf);
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*6/8,lungGrafTA,colorLineValGraf);
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*7/8,lungGrafTA,colorLineValGraf);
        tft.drawFastHLine(X0TA,Y0TA-altGrafTA*8/8,lungGrafTA,colorLineValGraf);
        tft.drawFastVLine(X0TA+lungGrafTA,Y0TA-altGrafTA,altGrafTA,colorLineValGraf);
        
        for(int i=1;i<CTA;i++)//Ridisegno tutto il nuovo grafico
        {
          tft.drawLine(passo*i+X0TA,Y0TA-(float)(((float)((graficoTA[i])*altGrafTA)/hgraftemp)),passo*i+X0TA-passo,Y0TA-(float)(((float)((graficoTA[i-1])*altGrafTA)/hgraftemp)),colorGrafA);
        }
      }
      
    }

    
  }while(1);
  drawMainMenu(); 
}
