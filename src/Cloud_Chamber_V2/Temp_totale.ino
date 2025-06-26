void Temp_gen()
{

  posmenu=false;
  ///DEFINIZIONE VARIABILI PER DISEGNO E USO
  
  float hgraftemp=80.0;//valore massimo del grafico nel primo quadrante
  float passo=lungGrafTT/(CTR-1.0);//passo tra un punto e il suo successivonel grafico

  ///DISEGNO DELLO SCHERMO
  //inizializzazione
  tft.setFont();
  tft.fillScreen(White);

  tft.drawBitmap(40,15,homeimg,50,50,Black);
  
 
  //Diagramma cartesiano
  tft.drawFastHLine(X0TT-20,Y0TT,lungGrafTT+20,Black);
  tft.drawFastHLine(X0TT-20,Y0TT+epsilon,lungGrafTT+20,Black);tft.drawFastHLine(X0TT-20,Y0TT+2*epsilon,lungGrafTT+20,Black);tft.drawFastHLine(X0TT-20,Y0TT-epsilon,lungGrafTT+20,Black);tft.drawFastHLine(X0TT-20,Y0TT-2*epsilon,lungGrafTT+20,Black);
  tft.drawFastVLine(X0TT,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);
  tft.drawFastVLine(X0TT+epsilon,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);tft.drawFastVLine(X0TT+2*epsilon,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);tft.drawFastVLine(X0TT-epsilon,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);tft.drawFastVLine(X0TT-2*epsilon,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);

  tft.drawFastHLine(X0TT,Y0TT-(-2*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(-1*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(1*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(2*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(3*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(4*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(5*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(6*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(7*altGrafTT/8),lungGrafTT,colorLineValGraf);
  tft.drawFastHLine(X0TT,Y0TT-(8*altGrafTT/8),lungGrafTT,colorLineValGraf);
  
  tft.drawFastVLine(X0TT+lungGrafTT,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,colorLineValGraf);

  //valori sugli assi
  tft.setTextSize(2);
  tft.setTextColor(Black);
  //tft.setCursor(X0TT+40,Y0TT-220);
  //tft.print("T(");
  //tft.print((char)167);
  //tft.print("C)");
  //tft.setCursor(410,280);
  //tft.print("t(s)");
  tft.setTextSize(1);
  tft.setCursor(X0TT-20,Y0TT-(8*altGrafTT/8+3));
  tft.print("80-");
  tft.setCursor(X0TT-20,Y0TT-(7*altGrafTT/8+3));
  tft.print("70-");
  tft.setCursor(X0TT-20,Y0TT-(6*altGrafTT/8+3));
  tft.print("60-");
  tft.setCursor(X0TT-20,Y0TT-(5*altGrafTT/8+3));
  tft.print("50-");
  tft.setCursor(X0TT-20,Y0TT-(4*altGrafTT/8+3));
  tft.print("40-");
  tft.setCursor(X0TT-20,Y0TT-(3*altGrafTT/8+3));
  tft.print("30-");
  tft.setCursor(X0TT-20,Y0TT-(2*altGrafTT/8+3));
  tft.print("20-");
  tft.setCursor(X0TT-20,Y0TT-(1*altGrafTT/8+3));
  tft.print("10-");
  tft.setCursor(X0TT-25,Y0TT-(-1*altGrafTT/8+3));
  tft.print("-10-");
  tft.setCursor(X0TT-25,Y0TT-(-2*altGrafTT/8+3));
  tft.print("-20-");
  
  //disegno grafico acquisito precedentemente
  for(int i=1;i<contvR;i++)
  {
    tft.drawLine(i*passo+X0TT,Y0TT-(float)(((float)((grafico1[i])*altGrafTT)/hgraftemp)),i*passo+X0TT-passo,Y0TT-(float)(((float)((grafico1[i-1])*altGrafTT)/hgraftemp)),colorGrafTT1);
    tft.drawLine(i*passo+X0TT,Y0TT-(float)(((float)((grafico2[i])*altGrafTT)/hgraftemp)),i*passo+X0TT-passo,Y0TT-(float)(((float)((grafico2[i-1])*altGrafTT)/hgraftemp)),colorGrafTT2);
    tft.drawLine(i*passo+X0TT,Y0TT-(float)(((float)((graficoN[i])*altGrafTT)/hgraftemp)),i*passo+X0TT-passo,Y0TT-(float)(((float)((graficoN[i-1])*altGrafTT)/hgraftemp)),colorGrafTTN);
  }

  //Legenda
  tft.fillRect(100,33,25,25,colorGrafTTN);
  tft.setCursor(130,42);
  tft.print("Lastra visibile");
  tft.fillRect(230,33,25,25,colorGrafTT1);
  tft.setCursor(260,42);
  tft.print("Lastra mediana");
  tft.fillRect(350,33,25,25,colorGrafTT2);
  tft.setCursor(380,42);
  tft.print("Lastra inferiore"); 
      
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
    Tempr1=digitalReadRame1;
    Tempr2=digitalReadRame2;
    TemprN=digitalReadRameNero;


    ///AGGIORNAMENTO GRAFICO
    if (contR==0)//Esegue un agiornamento ogni tot valori
    {

      if(contvR<CTR)//Finchè ci sto nel grafico inserisco i valori nell'array ed aggiungo una linea
      {
        tft.drawLine((contvR-1)*passo+X0TT,Y0TT-(float)(((float)((grafico1[contvR-1])*altGrafTT)/hgraftemp)),(contvR-2)*passo+X0TT,Y0TT-(float)(((float)((grafico1[contvR-2])*altGrafTT)/hgraftemp)),colorGrafTT1);
        tft.drawLine((contvR-1)*passo+X0TT,Y0TT-(float)(((float)((grafico2[contvR-1])*altGrafTT)/hgraftemp)),(contvR-2)*passo+X0TT,Y0TT-(float)(((float)((grafico2[contvR-2])*altGrafTT)/hgraftemp)),colorGrafTT2);
        tft.drawLine((contvR-1)*passo+X0TT,Y0TT-(float)(((float)((graficoN[contvR-1])*altGrafTT)/hgraftemp)),(contvR-2)*passo+X0TT,Y0TT-(float)(((float)((graficoN[contvR-2])*altGrafTT)/hgraftemp)),colorGrafTTN);   
      }
      else//quando l'array è pieno
      {
        
        //pulisco il grafico
        tft.fillRect(X0TT+2*epsilon,Y0TT-altGrafTT,lungGrafTT-2*epsilon,altGrafTT+2*altGrafTT/8,White);
        //Ridesegno gli elementi necssari nel grafico cartesiano
        tft.drawFastHLine(X0TT,Y0TT,lungGrafTT,Black);tft.drawFastHLine(X0TT,Y0TT+epsilon,lungGrafTT,Black);tft.drawFastHLine(X0TT,Y0TT+2*epsilon,lungGrafTT,Black);tft.drawFastHLine(X0TT,Y0TT-epsilon,lungGrafTT,Black);tft.drawFastHLine(X0TT,Y0TT-2*epsilon,lungGrafTT,Black);
        tft.drawFastVLine(X0TT,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);tft.drawFastVLine(X0TT+epsilon,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);tft.drawFastVLine(X0TT+2*epsilon,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,Black);
        
        tft.drawFastHLine(X0TT,Y0TT-(-2*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(-1*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(1*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(2*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(3*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(4*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(5*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(6*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(7*altGrafTT/8),lungGrafTT,colorLineValGraf);
        tft.drawFastHLine(X0TT,Y0TT-(8*altGrafTT/8),lungGrafTT,colorLineValGraf);
    
        tft.drawFastVLine(X0TT+lungGrafTT,Y0TT-altGrafTT,altGrafTT+2*altGrafTT/8,colorLineValGraf);
        
        for(int i=1;i<CTR;i++)//Ridisegno tutto il nuovo grafico
        {
          tft.drawLine(i*passo+X0TT,Y0TT-(float)(((float)((grafico1[i])*altGrafTT)/hgraftemp)),i*passo+X0TT-passo,Y0TT-(float)(((float)((grafico1[i-1])*altGrafTT)/hgraftemp)),colorGrafTT1);
          tft.drawLine(i*passo+X0TT,Y0TT-(float)(((float)((grafico2[i])*altGrafTT)/hgraftemp)),i*passo+X0TT-passo,Y0TT-(float)(((float)((grafico2[i-1])*altGrafTT)/hgraftemp)),colorGrafTT2);
          tft.drawLine(i*passo+X0TT,Y0TT-(float)(((float)((graficoN[i])*altGrafTT)/hgraftemp)),i*passo+X0TT-passo,Y0TT-(float)(((float)((graficoN[i-1])*altGrafTT)/hgraftemp)),colorGrafTTN);
        }
      }
      
    }





  }while(1);
  drawMainMenu();
}
