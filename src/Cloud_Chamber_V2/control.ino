void control()
{
  touchmap();
  //controllo accensione peltier
  if((!peltonaacc)&&pelt1acc)
  {
    //spegni pelteri 1
    tft.fillRect(36.8,100,89.6,41.6,colorpeloff);
    touchmap();
    pelt1acc=false;
    touchmap();
    tft.setCursor(66,113);
    touchmap();
    tft.setTextColor(Black);
    touchmap();
    tft.print("OFF");
    touchmap();
    digitalWrite(relayPeltier1, HIGH); //spegni rele
    touchmap();

  }
  touchmap();
  if((!peltonaacc)&&pelt2acc)
  {
    //spegni pelteri 2
    tft.fillRect(142.4,100,89.6,41.6,colorpeloff);
    touchmap();
    pelt2acc=false;
    touchmap();
    tft.setCursor(171.6,113);
    touchmap();
    tft.setTextColor(Black);
    touchmap();
    tft.print("OFF");
    touchmap();
    digitalWrite(relayPeltier2, HIGH); //spegni rele
    touchmap();
  }
  touchmap();
  if((!peltonaacc)&&pelt3acc)
  {
    //spegni pelteri 3
    tft.fillRect(248,100,89.6,41.6,colorpeloff);
    touchmap();
    pelt3acc=false;
    touchmap();
    tft.setCursor(277.2,113);
    touchmap();
    tft.setTextColor(Black);
    touchmap();
    tft.print("OFF");
    touchmap();
    digitalWrite(relayPeltier3, HIGH); //spegni rele
    touchmap();
  }
  touchmap();
  if((!peltonaacc)&&pelt4acc)
  {
    //spegni pelteri 4
    tft.fillRect(353.6,100,89.6,41.6,colorpeloff);
    touchmap();
    pelt4acc=false;
    touchmap();
    tft.setCursor(382.8,113);
    touchmap();
    tft.setTextColor(Black);
    touchmap();
    tft.print("OFF");
    touchmap();
    digitalWrite(relayPeltier4, LOW); //spegni rele
    touchmap();
  }
  touchmap();
/////////Inserimento nei grafici
  digitalReadAlcol=analogRead(AOUTpin)/10.0;
  touchmap();
  sensor3.requestTemperatures(); //Invio comando per leggere temperatura  
  touchmap();
  digitalReadRameNero = sensor3.getTempCByIndex(0);
  touchmap();
  //digitalReadRameNero=(random()%(maxtempr-mintempr))-abs(mintempr);
  sensor1.requestTemperatures(); //Invio comando per leggere temperatura  
  touchmap();
  digitalReadRame1 = sensor1.getTempCByIndex(0);
  touchmap();
  //digitalReadRame1=(random()%(maxtempr-mintempr))-abs(mintempr);
  sensor2.requestTemperatures(); //Invio comando per leggere temperatura 
  touchmap(); 
  digitalReadRame2 = sensor2.getTempCByIndex(0); 
  touchmap();
  //digitalReadRame2=(random()%(maxtempr-mintempr))-abs(mintempr);

  touchmap(); 
  digitalReadAcqua1 = getTemp1(); 
  touchmap();
 
  touchmap(); 
  digitalReadAcqua2 = getTemp2(); 
  touchmap();
  //sistemazione valori dell'acqua in caso i sensori non funzionino
  if(digitalReadAcqua1<-40||abs(digitalReadAcqua1-digitalReadAcqua1Prec)>7)
    {
      touchmap();
      if(contvTA==0)
      {
        touchmap();
        digitalReadAcqua1=val_ott_ac;
        touchmap();
      }
      else
      {
        digitalReadAcqua1=digitalReadAcqua1Prec;
        touchmap();
      }
    }
    if(digitalReadAcqua2<-40||abs(digitalReadAcqua2-digitalReadAcqua2Prec)>7)
    {
      touchmap();
      if(contvTA==0)
      {
        touchmap();
        digitalReadAcqua2=val_ott_ac;
        touchmap();
      }
      else
      {
        digitalReadAcqua2=digitalReadAcqua2Prec;
        touchmap();
      }
    }
    digitalReadAcqua1Prec=digitalReadAcqua1;
    touchmap();
    digitalReadAcqua2Prec=digitalReadAcqua2;
    touchmap();
  //digitalReadAcqua1=(random()%40)+10;
  //touchmap();
  //digitalReadAcqua2=(random()%40)+10;
  //touchmap();
  
  
  //Alcol
  contAl++;
  touchmap();
  if(contAl>=numciclipreimmA)
  {
    contAl=0;
    touchmap();
    if(contvAl<CA)
    {
      graficoAl[contvAl]=digitalReadAlcol;
      touchmap();
      contvAl++;
      touchmap();
    }
    else
    {
      for(int i=0;i<CA-1;i++)
      {
        graficoAl[i]=graficoAl[i+1];
        touchmap();
      }
      graficoAl[CA-1]=digitalReadAlcol;
      touchmap();
    }
    
    
  }

  //Acqua
  touchmap();
  contTA++;
  if(contTA>=numciclipreimmTA)
  {
    touchmap();
    
    contTA=0;
    touchmap();
    if(contvTA<CTA)
    {
      graficoTA[contvTA]=(digitalReadAcqua1+digitalReadAcqua2)/2.0;
      touchmap();
      contvTA++;
      touchmap();
    }
    else
    {
      for(int i=0;i<CTA-1;i++)
      {
        graficoTA[i]=graficoTA[i+1];
        touchmap();
      }
      graficoTA[CTA-1]=(digitalReadAcqua1+digitalReadAcqua2)/2.0;
      touchmap();
    }

    
    
  }
  
  digitalR1=false;
  touchmap();
  digitalR2=false;
  touchmap();
  digitalRN=false;
  touchmap();
  
  if(digitalReadRame1==-127.00)
  {
    touchmap();
    digitalR1=true;
  }
    
  if(digitalReadRame2==-127.00)
  {
    digitalR2=true;
    touchmap();
  }

  if(digitalReadRameNero==-127.00)
  {
    digitalRN=true;
    touchmap();
  }

    if(!posmenu)
  {
    numer=0;
    touchmap();
    if(digitalReadAlcol>val_ott+erassol||digitalReadAlcol<val_ott-erassol)
      numer++;
    if(digitalReadRameNero>val_ott_rn+errrn||digitalReadRameNero<val_ott_rn-errrn)
      numer++;
    if(digitalReadRame1>val_ott_r1+errr1||digitalReadRame1<val_ott_r1-errr1)
      numer++; 
    if(digitalReadRame2>val_ott_r2+errr2||digitalReadRame2<val_ott_r2-errr2)
      numer++;
    if(((digitalReadAcqua1+digitalReadAcqua2)/2.0)>val_ott_ac+errac||((digitalReadAcqua1+digitalReadAcqua2)/2.0)<val_ott_ac-errac)
      numer++;
    touchmap();

    senser=0;
    touchmap();
    if(digitalR1)
    {
      numer--;
      senser++;
      touchmap();
    }
    if(digitalR2)
    {
      numer--;
      senser++;
      touchmap();
    }
    if(digitalRN)
    {
      numer--;
      senser++;
      touchmap();
    }
    if(senser!=senserprec&&senser!=0)
    {
      tft.fillRect(10,40,15,22,White);
      touchmap();
      tft.setCursor(10,40);
      touchmap();
      tft.setTextSize(2);
      touchmap();
      tft.setTextColor(Red);
      touchmap();
      tft.print("E");
      touchmap();
      tft.setTextSize(1);
      touchmap();
      tft.setCursor(20,55);
      touchmap();
      tft.print(senser);
      touchmap();
    }
    if(senser==0)
    {
      tft.fillRect(10,40,15,22,White);
      touchmap();
    }
    senserprec=senser;
    touchmap();

    if(numer!=numerprec&&numer!=0)
    {
      tft.fillRect(35,9,10,15,White);
      touchmap();
      tft.setCursor(35,9);
      touchmap();
      tft.setTextSize(2);
      touchmap();
      tft.setTextColor(Red);
      touchmap();
      tft.print(numer);
      touchmap();
      tft.drawBitmap(40,15,homeimg,50,50,Red);
      touchmap();
      disegnocasetta=true;
      touchmap();
    }
    if(disegnocasetta==true&&numer==0)
    {
      tft.fillRect(35,9,10,15,White);
      touchmap();
      tft.drawBitmap(40,15,homeimg,50,50,Black);
      touchmap();
      disegnocasetta=false;
      touchmap();
    }
    numerprec=numer; 
    touchmap();
  }



  //Lastre di rame
  contR++;
  touchmap();
  if (contR>=numciclipreimmTR)//Esegue un agiornamento ogni tot valori
    {
      contR=0;//riparte il conteggio per l'nserimento nel grafico del prossimo valore
      touchmap();
      if(digitalR1)
      {
        if(contvR==0)
        {
          digitalReadRame1=val_ott_r1;
          touchmap();
        }
        else
        {
          digitalReadRame1=grafico1[contvR-1];
          touchmap();
        }
      }
      if(digitalR2)
      {
        if(contvR==0)
        {
          digitalReadRame2=val_ott_r2;
          touchmap();
        }
        else
        {
          digitalReadRame2=grafico2[contvR-1];
          touchmap();
        }
      }
      if(digitalRN)
      { 
        if(contvR==0)
        {
          digitalReadRameNero=val_ott_rn;
          touchmap();
        }
        else
        {
          digitalReadRameNero=graficoN[contvR-1];
          touchmap();
        }
      }
      if(contvR<CTR)//Finchè ci sto nel grafico inserisco i valori nell'array ed aggiungo una linea
      {
        grafico1[contvR]=digitalReadRame1;
        touchmap();
        grafico2[contvR]=digitalReadRame2;
        touchmap();
        graficoN[contvR]=digitalReadRameNero;
        touchmap();
        contvR++;
        touchmap();
      }
      else
      {
        for(int i=0; i<(CTR-1);i++)//sposto tutti gli elementi dell'array un posto indietro
        {
          grafico1[i]=grafico1[i+1];
          touchmap();
          grafico2[i]=grafico2[i+1];
          touchmap();
          graficoN[i]=graficoN[i+1];
          touchmap();
        }
        //inserisco i nuovi elementi
        grafico1[(CTR-1)]=digitalReadRame1;
        touchmap();
        grafico2[(CTR-1)]=digitalReadRame2;
        touchmap();
        graficoN[(CTR-1)]=digitalReadRameNero;
        touchmap();
      } 
    
    
    } 
  touchmap();
  
}
