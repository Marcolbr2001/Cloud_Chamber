void temperaturarame1()
{

  posmenu=false;
  ///DEFINIZIONE VARIABILI PER DISEGNO E USO
  float tempprec=-50;
  int h,hp=-20;
  float hgraftemp=80.0;//valore massimo del grafico nel primo quadrante
  float passo=lungGrafTR/(CTR-1.0);//passo tra un punto e il suo successivonel grafico

  ///DISEGNO DELLO SCHERMO
  //inizializzazione
  tft.setFont();
  tft.fillScreen(White);

  tft.drawBitmap(40,15,homeimg,50,50,Black);
  
 
  //Diagramma cartesiano
  tft.drawFastHLine(X0TR-20,Y0TR,lungGrafTR+20,Black);
  tft.drawFastHLine(X0TR-20,Y0TR+epsilon,lungGrafTR+20,Black);tft.drawFastHLine(X0TR-20,Y0TR+2*epsilon,lungGrafTR+20,Black);tft.drawFastHLine(X0TR-20,Y0TR-epsilon,lungGrafTR+20,Black);tft.drawFastHLine(X0TR-20,Y0TR-2*epsilon,lungGrafTR+20,Black);
  tft.drawFastVLine(X0TR,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);
  tft.drawFastVLine(X0TR+epsilon,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);tft.drawFastVLine(X0TR+2*epsilon,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);tft.drawFastVLine(X0TR-epsilon,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);tft.drawFastVLine(X0TR-2*epsilon,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);

  tft.drawFastHLine(X0TR,Y0TR-(-2*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(-1*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(1*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(2*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(3*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(4*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(5*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(6*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(7*altGrafTR/8),lungGrafTR,colorLineValGraf);
  tft.drawFastHLine(X0TR,Y0TR-(8*altGrafTR/8),lungGrafTR,colorLineValGraf);
  
  tft.drawFastVLine(X0TR+lungGrafTR,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,colorLineValGraf);

  //valori sugli assi
  tft.setTextSize(2);
  tft.setTextColor(Black);
  tft.setCursor(X0TR-20,Y0TR-215);
  tft.print("T(");
  tft.print((char)167);
  tft.print("C)");
  //tft.setCursor(410,280);
  //tft.print("t(s)");
  tft.setTextSize(1);
  tft.setCursor(X0TR-20,Y0TR-(8*altGrafTR/8+3));
  tft.print("80-");
  tft.setCursor(X0TR-20,Y0TR-(7*altGrafTR/8+3));
  tft.print("70-");
  tft.setCursor(X0TR-20,Y0TR-(6*altGrafTR/8+3));
  tft.print("60-");
  tft.setCursor(X0TR-20,Y0TR-(5*altGrafTR/8+3));
  tft.print("50-");
  tft.setCursor(X0TR-20,Y0TR-(4*altGrafTR/8+3));
  tft.print("40-");
  tft.setCursor(X0TR-20,Y0TR-(3*altGrafTR/8+3));
  tft.print("30-");
  tft.setCursor(X0TR-20,Y0TR-(2*altGrafTR/8+3));
  tft.print("20-");
  tft.setCursor(X0TR-20,Y0TR-(1*altGrafTR/8+3));
  tft.print("10-");
  tft.setCursor(X0TR-25,Y0TR-(-1*altGrafTR/8+3));
  tft.print("-10-");
  tft.setCursor(X0TR-25,Y0TR-(-2*altGrafTR/8+3));
  tft.print("-20-");

  //disegno grafico acquisito precedentemente
  for(int i=1;i<contvR;i++)
  {
    tft.drawLine(i*passo+X0TR,Y0TR-(float)(((float)((grafico1[i])*altGrafTR)/hgraftemp)),i*passo+X0TR-passo,Y0TR-(float)(((float)((grafico1[i-1])*altGrafTR)/hgraftemp)),colorGrafTT1);
  }

  //disegni termometri
  tft.fillCircle(XCTR1,YCTR1,RETR1,Black);
  tft.fillRoundRect(XCTR1-(RETR1*4/5)/2,YCTR1-(HTR1+RETR1+(+10)),RETR1*4/5,HTR1+RETR1,(RETR1*4/5)/2,Black);
  tft.fillCircle(XCTR1,YCTR1,RITR1,colorTermR1);
  tft.setTextColor(Black);
  tft.setTextSize(2);
  tft.setCursor(XCTR1+28,YCTR1+50);
  tft.print((char)167);
  tft.print("C");
  
      
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
    Temp=digitalReadRame1;


    
      
    ///AGGIORNAMENTO DISEGNI TERMOMETRI
    //TERMOMETRO
    if(Temp>tempprec)//Aggiornamento in positivo
    {
      tft.fillRect(XCTR1-45,YCTR1+40,72,35,White);
      tft.setCursor(XCTR1-43,YCTR1+50);
      if(Temp>-10)
        tft.print(" ");
      if(Temp>=0&&Temp<10)
        tft.print(" ");
      tft.print((Temp));

      h=(Temp-mintempr)*HTR1/abs(mintempr-maxtempr);
      tft.fillRect(XCTR1-(RETR1*4/5)/2+(RETR1*4/5)/2/2,YCTR1-(h+RETR1),(RETR1*4/5)/2,h-hp,colorTermR1); 
      hp=h;
    }
    if(Temp<tempprec)//aggiornamento in negativo
    {
      tft.fillRect(XCTR1-45,YCTR1+40,72,35,White); 
      tft.setCursor(XCTR1-43,YCTR1+50);
      if(Temp>-10)
        tft.print(" ");
      if(Temp>=0&&Temp<10)
        tft.print(" ");
      tft.print((Temp));

      h=(Temp-mintempr)*HTR1/abs(mintempr-maxtempr);
      tft.fillRect(XCTR1-(RETR1*4/5)/2+(RETR1*4/5)/2/2,YCTR1-(hp+RETR1),(RETR1*4/5)/2,hp-h,Black); 
      hp=h;
    }
    

    //Inizializzazione delle variabili precedenti per il confronto nel prossimo ciclo
    tempprec=Temp;

    ///AGGIORNAMENTO GRAFICO
    if (contR==0)//Esegue un agiornamento ogni tot valori
    {
      if(contvR<CTR)//Finchè ci sto nel grafico inserisco i valori nell'array ed aggiungo una linea
      {
        tft.drawLine((contvR-1)*passo+X0TR,Y0TR-(float)(((float)((grafico1[contvR-1])*altGrafTR)/hgraftemp)),(contvR-2)*passo+X0TR,Y0TR-(float)(((float)((grafico1[contvR-2])*altGrafTR)/hgraftemp)),colorGrafTT1);
      }
      else//quando l'array è pieno
      {
        //pulisco il grafico
        tft.fillRect(X0TR+2*epsilon,Y0TR-altGrafTR,lungGrafTR-2*epsilon,altGrafTR+2*altGrafTR/8,White);
        //Ridesegno gli elementi necssari nel grafico cartesiano
        tft.drawFastHLine(X0TR,Y0TR,lungGrafTR,Black);tft.drawFastHLine(X0TR,Y0TR+epsilon,lungGrafTR,Black);tft.drawFastHLine(X0TR,Y0TR+2*epsilon,lungGrafTR,Black);tft.drawFastHLine(X0TR,Y0TR-epsilon,lungGrafTR,Black);tft.drawFastHLine(X0TR,Y0TR-2*epsilon,lungGrafTR,Black);
        tft.drawFastVLine(X0TR,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);tft.drawFastVLine(X0TR+epsilon,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);tft.drawFastVLine(X0TR+2*epsilon,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,Black);
        
        tft.drawFastHLine(X0TR,Y0TR-(-2*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(-1*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(1*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(2*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(3*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(4*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(5*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(6*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(7*altGrafTR/8),lungGrafTR,colorLineValGraf);
        tft.drawFastHLine(X0TR,Y0TR-(8*altGrafTR/8),lungGrafTR,colorLineValGraf);
    
        tft.drawFastVLine(X0TR+lungGrafTR,Y0TR-altGrafTR,altGrafTR+2*altGrafTR/8,colorLineValGraf);
        
        for(int i=1;i<CTR;i++)//Ridisegno tutto il nuovo grafico
        {
          tft.drawLine(i*passo+X0TR,Y0TR-(float)(((float)((grafico1[i])*altGrafTR)/hgraftemp)),i*passo+X0TR-passo,Y0TR-(float)(((float)((grafico1[i-1])*altGrafTR)/hgraftemp)),colorGrafTT1);
        }
      }
      
    }

  }while(1);
  drawMainMenu();
}
