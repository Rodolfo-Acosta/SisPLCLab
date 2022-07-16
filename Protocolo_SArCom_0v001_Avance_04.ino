/*    1.-    Incorporar el CRC
 *    2.-    Enviar BufferCom
 * ToDoList
 * **************************************************  
 *    Crear 
 * ****************   Funciones   ******************
 1.-    void DescargaBufferComToMapa(void)
 2.-    Crear Class part 1
 3.-    App_01   Leer un bit  y AN0
 * **************************************************     
 * **************************************************
 * 
 *  SArCom 0v0001  
           16 SalBin
             8 SalAn (16  bits)
           16 EnBin
             8 EnAn (16  bits)
 * 
 * 
 Mapa 
 0x00   regDireccion
 0x01   regComando
 0x02   regEstado
 0x03   regEnBinB0    // b0  -  b7
 0x04   regEnBinB1    // b8  -  b15
 0x05   regSalBinB0   // b0  -  b7
 0x06   regSalBinB1   // b8  -  b15
 0x07   regEnAnB0
 0x08   regEnAnB0
 0x09   regEnAnB0
 0x0A   regEnAnB0
 0x0B   regEnAnB0
 0x0C   regEnAnB0
 0x0D   regEnAnB0
 0x0E   regEnAnB0
 0x0F   Direccion
 0x10   Direccion
 0x11   Direccion
 0x12   Direccion
 0x13   Direccion
 0x14   Direccion
 0x15   Direccion
 0x16   Direccion
 0x17   Direccion
 0x18   Direccion

 */


struct struct_SArCom_MRD {
    uint8_t   Direccion ;
    uint8_t   Comando ;
    uint8_t   Status ;                    
    uint16_t  EnAn[8] ;
    uint16_t  SalAn[8] ;
    uint16_t  CRC16 ;       
    union {
      uint32_t  Reg;    
      struct {
        bool b0 : 1 ;
        bool b1 : 1 ;
        bool b2 : 1 ;
        bool b3 : 1 ;    
        bool b4 : 1 ;
        bool b5 : 1 ;
        bool b6 : 1 ;
        bool b7 : 1 ;     
        bool b8 : 1 ;
        bool b9 : 1 ;
        bool b10 : 1 ;
        bool b11 : 1 ;    
        bool b12 : 1 ;
        bool b13 : 1 ;
        bool b14 : 1 ;
        bool b15 : 1 ;    
        bool b16 : 1 ;
        bool b17 : 1 ;
        bool b18 : 1 ;
        bool b19 : 1 ;    
        bool b20 : 1 ;
        bool b21 : 1 ;
        bool b22 : 1 ;
        bool b23 : 1 ;     
        bool b24 : 1 ;
        bool b25 : 1 ;
        bool b26 : 1 ;
        bool b27 : 1 ;    
        bool b28 : 1 ;
        bool b29 : 1 ;
        bool b30 : 1 ;
        bool b31 : 1 ;  
      };
    } EnBin;    
    union {
      uint32_t  Reg;    
      struct {
        bool b0 : 1;
        bool b1 : 1 ;
        bool b2 : 1 ;
        bool b3 : 1 ;    
        bool b4 : 1 ;
        bool b5 : 1 ;
        bool b6 : 1 ;
        bool b7 : 1 ;     
        bool b8 : 1 ;
        bool b9 : 1 ;
        bool b10 : 1 ;
        bool b11 : 1 ;    
        bool b12 : 1 ;
        bool b13 : 1 ;
        bool b14 : 1 ;
        bool b15 : 1 ; 
        bool b16 : 1 ;
        bool b17 : 1 ;
        bool b18 : 1 ;
        bool b19 : 1 ;    
        bool b20 : 1 ;
        bool b21 : 1 ;
        bool b22 : 1 ;
        bool b23 : 1 ;     
        bool b24 : 1 ;
        bool b25 : 1 ;
        bool b26 : 1 ;
        bool b27 : 1 ;    
        bool b28 : 1 ;
        bool b29 : 1 ;
        bool b30 : 1 ;
        bool b31 : 1 ;             
      };
    } SalBin;       
  };

struct struct_SArCom_MRD  SArCom_MRD = {0} ;

#define   EnAn0         SArCom_MRD.EnAn[0]
#define   EnAn1         SArCom_MRD.EnAn[1]
#define   EnAn2         SArCom_MRD.EnAn[2]
#define   EnAn3         SArCom_MRD.EnAn[3]
#define   EnAn4         SArCom_MRD.EnAn[4]
#define   EnAn5         SArCom_MRD.EnAn[5]
#define   EnAn6         SArCom_MRD.EnAn[6]
#define   EnAn7         SArCom_MRD.EnAn[7]

#define   SalAn0         SArCom_MRD.SalAn[0]
#define   SalAn1         SArCom_MRD.SalAn[1]
#define   SalAn2         SArCom_MRD.SalAn[2]
#define   SalAn3         SArCom_MRD.SalAn[3]
#define   SalAn4         SArCom_MRD.SalAn[4]
#define   SalAn5         SArCom_MRD.SalAn[5]
#define   SalAn6         SArCom_MRD.SalAn[6]
#define   SalAn7         SArCom_MRD.SalAn[7]

#define   EnBin0        SArCom_MRD.EnBin.b0
#define   EnBin1        SArCom_MRD.EnBin.b1
#define   EnBin2        SArCom_MRD.EnBin.b2
#define   EnBin3        SArCom_MRD.EnBin.b3
#define   EnBin4        SArCom_MRD.EnBin.b4
#define   EnBin5        SArCom_MRD.EnBin.b5
#define   EnBin6        SArCom_MRD.EnBin.b6
#define   EnBin7        SArCom_MRD.EnBin.b7
#define   EnBin8        SArCom_MRD.EnBin.b8
#define   EnBin9        SArCom_MRD.EnBin.b9
#define   EnBin10       SArCom_MRD.EnBin.b10
#define   EnBin11       SArCom_MRD.EnBin.b11
#define   EnBin12       SArCom_MRD.EnBin.b12
#define   EnBin13       SArCom_MRD.EnBin.b13
#define   EnBin14       SArCom_MRD.EnBin.b14
#define   EnBin15       SArCom_MRD.EnBin.b15
#define   EnBin16       SArCom_MRD.EnBin.b16
#define   EnBin17       SArCom_MRD.EnBin.b17
#define   EnBin18       SArCom_MRD.EnBin.b18
#define   EnBin19       SArCom_MRD.EnBin.b19
#define   EnBin20       SArCom_MRD.EnBin.b20
#define   EnBin21       SArCom_MRD.EnBin.b21
#define   EnBin22       SArCom_MRD.EnBin.b22
#define   EnBin23       SArCom_MRD.EnBin.b23
#define   EnBin24       SArCom_MRD.EnBin.b24
#define   EnBin25       SArCom_MRD.EnBin.b25
#define   EnBin26       SArCom_MRD.EnBin.b26
#define   EnBin27       SArCom_MRD.EnBin.b27
#define   EnBin28       SArCom_MRD.EnBin.b28
#define   EnBin29       SArCom_MRD.EnBin.b29
#define   EnBin30       SArCom_MRD.EnBin.b30
#define   EnBin31       SArCom_MRD.EnBin.b31



#define   SalBin0        SArCom_MRD.SalBin.b0
#define   SalBin1        SArCom_MRD.SalBin.b1
#define   SalBin2        SArCom_MRD.SalBin.b2
#define   SalBin3        SArCom_MRD.SalBin.b3
#define   SalBin4        SArCom_MRD.SalBin.b4
#define   SalBin5        SArCom_MRD.SalBin.b5
#define   SalBin6        SArCom_MRD.SalBin.b6
#define   SalBin7        SArCom_MRD.SalBin.b7
#define   SalBin8        SArCom_MRD.SalBin.b8
#define   SalBin9        SArCom_MRD.SalBin.b9
#define   SalBin10       SArCom_MRD.SalBin.b10
#define   SalBin11       SArCom_MRD.SalBin.b11
#define   SalBin12       SArCom_MRD.SalBin.b12
#define   SalBin13       SArCom_MRD.SalBin.b13
#define   SalBin14       SArCom_MRD.SalBin.b14
#define   SalBin15       SArCom_MRD.SalBin.b15

#define   SalBin16       SArCom_MRD.SalBin.b16
#define   SalBin17       SArCom_MRD.SalBin.b17
#define   SalBin18       SArCom_MRD.SalBin.b18
#define   SalBin19       SArCom_MRD.SalBin.b19
#define   SalBin20       SArCom_MRD.SalBin.b20
#define   SalBin21       SArCom_MRD.SalBin.b21
#define   SalBin22       SArCom_MRD.SalBin.b22
#define   SalBin23       SArCom_MRD.SalBin.b23
#define   SalBin24       SArCom_MRD.SalBin.b24
#define   SalBin25       SArCom_MRD.SalBin.b25
#define   SalBin26       SArCom_MRD.SalBin.b26
#define   SalBin27       SArCom_MRD.SalBin.b27
#define   SalBin28       SArCom_MRD.SalBin.b28
#define   SalBin29       SArCom_MRD.SalBin.b29
#define   SalBin30       SArCom_MRD.SalBin.b30
#define   SalBin31       SArCom_MRD.SalBin.b31

//  **************************
//          App  01
//  **************************
    
#define   xb0Pin    4   // entrada binaria pin D4

//  **************************


// Define las variables

byte BufferCom[30] ;

int canCarRec, k, j=0 ;
boolean bTramaRecibida = false ;
boolean bTransmiteTrama = false ;
boolean bTramaRecibidaOK = false ;

//unsigned char *PtrBloMem ;
unsigned int canCarBloMem = 0 ;
//unsigned int CRC16 = 0 ;



void setup(){
//Inicializa el puerto serial 
  Serial.begin(9600);
  Serial.setTimeout(20) ;
  while (!Serial);  // Espera que estar disponible

  delay(1100);
  pinMode(xb0Pin, INPUT) ;

}

void CargaMapaToBufferCom(void){
    int i = 0;
    int canCarBufferCom = 0 ;
    byte* ptrBufferCom ;
    
    SArCom_MRD.Direccion=0x01 ;
    SArCom_MRD.Comando=0x03 ; 
    SArCom_MRD.Status=0x11 ;
    SArCom_MRD.EnAn[0]=0x6121 ;
    SArCom_MRD.EnAn[1]=0x7112 ;    
    SArCom_MRD.EnAn[2]=0x8117 ;
    SArCom_MRD.EnAn[3]=0x9793 ;
    SArCom_MRD.EnAn[4]=0x9794 ;
    SArCom_MRD.EnAn[5]=0x9795 ;
    SArCom_MRD.EnAn[6]=0x9796 ;
    SArCom_MRD.EnAn[7]=0x9797 ;               
    SArCom_MRD.EnBin.Reg =0x10562398 ;    
    SArCom_MRD.CRC16 =0x1291 ;
              
    BufferCom[i++] = SArCom_MRD.Direccion ;
    BufferCom[i++] = SArCom_MRD.Comando ;
    BufferCom[i++] = SArCom_MRD.Status;


    for(int y =0; y < 8; y++){
      BufferCom[i++] =  highByte(SArCom_MRD.EnAn[y]) ;
      BufferCom[i++] =  lowByte(SArCom_MRD.EnAn[y]) ;
    }
   
    BufferCom[i++] = longToByteB3(SArCom_MRD.EnBin.Reg) ;
    BufferCom[i++] = longToByteB2(SArCom_MRD.EnBin.Reg) ;
    BufferCom[i++] = longToByteB1(SArCom_MRD.EnBin.Reg) ;
    BufferCom[i++] = longToByteB0(SArCom_MRD.EnBin.Reg) ;
    
// ------------------------------------------------
// ------------------------------------------------
    ptrBufferCom = &BufferCom[0] ; 
    canCarBufferCom = i ;
    SArCom_MRD.CRC16 = CalculaCRC16(canCarBufferCom, ptrBufferCom);
 
    BufferCom[i++] = lowByte(SArCom_MRD.CRC16) ;
    BufferCom[i++] = highByte(SArCom_MRD.CRC16) ;
    canCarBufferCom = i ;   

   for(int y = 0; y < canCarBufferCom ; y++){    
      Serial.write(BufferCom[y]);
   }   
   bTramaRecibida = false;
   bTramaRecibidaOK = false;
   // Serial.flush();             
 /*     
// -------------------------------------------------   
// ------------------------------------------------- 
    Serial.println("wwwwwwwwwwwwwwwwww \n");    
    for(int y = 0; y < canCarBufferCom ; y++){    
        Serial.print(BufferCom[y], HEX);
        Serial.print(" ");
    }
      Serial.println("\n");  
      Serial.println("wwwwwwwwwwwwwwwwww \n");     

      Serial.println("\n");  
   
 
// -------------------------------------------------   
// ------------------------------------------------- 
    Serial.println("------------  ") ;  
    Serial.print("i = ") ;  Serial.println(i) ;  
    Serial.println("------------  ") ;  

    for(int y = 0; y < i; y++){
      Serial.println(BufferCom[y], HEX) ;   
    }

// ------------------------------------------------
// ------------------------------------------------
    ptrBufferCom = &BufferCom[0] ; 
    canCarBufferCom = i ;
    SArCom_MRD.CRC16 = CalculaCRC16(canCarBufferCom, ptrBufferCom);
    Serial.println("**********");
    Serial.println(SArCom_MRD.CRC16, HEX) ; 
    Serial.println("**********");      
// -------------------------------------------------   
// ------------------------------------------------- 
 */     
}

void descargaBufferComToMapa(void){
    int i = 0;

//    -------------  Inicio de descarga de BufferCom al Mapa -------------
    i++ ; i++;
        
    SArCom_MRD.Comando  = BufferCom[i++]  ;
    SArCom_MRD.Status = BufferCom[i++] ;
     
    for(int y =0; y< 4; y++){
      SArCom_MRD.SalAn[y] = (BufferCom[i++] << 8) | BufferCom[i++] ;
    }
    SArCom_MRD.EnBin.Reg = (BufferCom[i++] << 8) | BufferCom[i++]  ;

    SArCom_MRD.CRC16 = (BufferCom[i++] << 8) | BufferCom[i++] ;

//    -------------  Fin de descarga de BufferCom al Mapa -------------


    Serial.println(" ------------  ") ;  
    Serial.print("i = ") ;  Serial.println(i) ;  
    Serial.println(" ------------  ") ;  
  
    for(int y = 0; y < i; y++){
      Serial.println(BufferCom[y], HEX) ;   
    }
    
}

void ImprimeRegControl(void){
    Serial.print("Direccion: ") ;   Serial.println(SArCom_MRD.Direccion, HEX) ;
    Serial.print("Comando: ") ;           Serial.println(SArCom_MRD.Comando, HEX) ;
    Serial.print("Status: ") ;            Serial.println(SArCom_MRD.Status, HEX) ;
    Serial.print("CRC16: ");              Serial.println(SArCom_MRD.CRC16, HEX) ;
}

void ImprimeEnAn(void){
    Serial.print(EnAn0, HEX);   Serial.print(" ");     
    Serial.print(EnAn1, HEX);   Serial.print(" ");    
    Serial.print(EnAn2, HEX);   Serial.print(" ");   
    Serial.print(EnAn3, HEX);   Serial.println(" "); 
}
void ImprimeSalAn(void){
    Serial.print(SalAn0, HEX);   Serial.print(" ");     
    Serial.print(SalAn1, HEX);   Serial.print(" ");    
    Serial.print(SalAn2, HEX);   Serial.print(" ");   
    Serial.print(SalAn3, HEX);   Serial.println(" "); 
}
    
void ImprimeEnBin(void){

    Serial.println(SArCom_MRD.EnBin.Reg, HEX); 
    Serial.println(SArCom_MRD.EnBin.Reg, BIN);       
    Serial.print(EnBin15, BIN);   Serial.print(" ");     
    Serial.print(EnBin14, BIN);   Serial.print(" ");    
    Serial.print(EnBin13, BIN);   Serial.print(" ");   
    Serial.print(EnBin12, BIN);   Serial.print(" ");     
    Serial.print(EnBin11, BIN);   Serial.print(" ");    
    Serial.print(EnBin10, BIN);   Serial.print(" ");   
    Serial.print(EnBin9, BIN);    Serial.print(" ");    
    Serial.print(EnBin8, BIN);    Serial.print(" ");   
    Serial.print(EnBin7, BIN);    Serial.print(" ");     
    Serial.print(EnBin6, BIN);    Serial.print(" ");    
    Serial.print(EnBin5, BIN);    Serial.print(" ");   
    Serial.print(EnBin4, BIN);    Serial.print(" ");     
    Serial.print(EnBin3, BIN);    Serial.print(" ");    
    Serial.print(EnBin2, BIN);    Serial.print(" ");   
    Serial.print(EnBin1, BIN);    Serial.print(" ");    
    Serial.print(EnBin0, BIN);    Serial.println(" ");   
}

void ImprimeSalBin(void){

    Serial.println(SArCom_MRD.SalBin.Reg, HEX); 
    Serial.println(SArCom_MRD.SalBin.Reg, BIN);       
    Serial.print(SalBin15, BIN);   Serial.print(" ");     
    Serial.print(SalBin14, BIN);   Serial.print(" ");    
    Serial.print(SalBin13, BIN);   Serial.print(" ");   
    Serial.print(SalBin12, BIN);   Serial.print(" ");     
    Serial.print(SalBin11, BIN);   Serial.print(" ");    
    Serial.print(SalBin10, BIN);   Serial.print(" ");   
    Serial.print(SalBin9, BIN);    Serial.print(" ");    
    Serial.print(SalBin8, BIN);    Serial.print(" ");   
    Serial.print(SalBin7, BIN);    Serial.print(" ");     
    Serial.print(SalBin6, BIN);    Serial.print(" ");    
    Serial.print(SalBin5, BIN);    Serial.print(" ");   
    Serial.print(SalBin4, BIN);    Serial.print(" ");     
    Serial.print(SalBin3, BIN);    Serial.print(" ");    
    Serial.print(SalBin2, BIN);    Serial.print(" ");   
    Serial.print(SalBin1, BIN);    Serial.print(" ");    
    Serial.print(SalBin0, BIN);    Serial.println(" ");   
}


// **********************************************************
//      Calcula el CRC de 16 bits
// **********************************************************


unsigned int CalculaCRC16( unsigned int canByteBloMem, 
                           unsigned char *ptrBloMem) {
// Declaraciones

 unsigned int CRC, CRC_Temp, i, j  ;
 unsigned char CRCH, CRCL ;
 //unsigned char BloMem[8]={ 0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B }; // CRC16 = 0x0BC4

//  Ejemplo funcion Modbus  
//  Dir    Fun3    DirIniH   DirIniH    DirFinH   DirFin    CRCL     CRCH   
//  0x01   0x03     0x00      0x00       0x00      0x02     0xC4     0x0B


  CRC = 0xFFFF ;
  for (i=0; i < canByteBloMem; i++){
    CRC = CRC ^ (unsigned int)*ptrBloMem ;
    ptrBloMem++;
        
    for (j=0; j<8; j++){ 
      CRC_Temp = CRC ;
      CRC = CRC >> 1 ;
      if((CRC_Temp & 0x0001) == 1 ) CRC = CRC ^ 0xA001 ;
    }
  }
  CRCL = CRC & 0x00FF ;
  CRCH = (CRC >> 8) & 0x00FF ;
  
  return(CRC);
}


byte longToByteB0(long Val){
  Val = (Val & 0x000000FF) ;
  return (byte)Val;
}
byte longToByteB1(long Val){
  Val = (Val & 0x0000FF00) >> 8 ;
  return (byte)Val;  
}

byte longToByteB2(long Val){
  Val = (Val & 0x00FF0000) >> 16 ;
  return (byte)Val; 
}

byte longToByteB3(long Val){
  Val = (Val & 0xFF000000) >> 24 ;
  return (byte)Val;  
}

void AnalizaTramaRec(void){
  byte SXCom_Direccion = 0x01 ;
  byte SXCom_Comando = 0x03 ;
  byte SXCom_Status = 0x11 ;
      
  if ((BufferCom[0]== SXCom_Direccion) &&   
      (BufferCom[1]== SXCom_Comando) &&
      (BufferCom[2]== SXCom_Status)){
      bTramaRecibidaOK = true ;  
  }
  else {
    bTramaRecibidaOK = false ; 
    Serial.flush();  
  }
}
void loop() {
  int xAn0 ;
  bool xb0 ; 

  xAn0 = analogRead(A0);
  xb0 = digitalRead(xb0Pin) ;
  SArCom_MRD.EnAn[0] = xAn0 ;
  SArCom_MRD.EnBin.b0 = xb0 ;
  unsigned char i, j ;
//  if (bTramaRecibida) AnalizaTramaRec(); 
  if (bTramaRecibida) CargaMapaToBufferCom() ; //SendData(); //  if (bTramaRecibidaOK) SendData();
  delay(10);
/*   
  Serial.println("  ********  Inicio Prueba Mapa - Buffer    **** ");  
    CargaMapaToBufferCom();
  Serial.println("  ********  Fin Prueba Mapa - Buffer   **** ");    
            
  delay(8000);
  */
}


void serialEvent(){
  while (Serial.available()){
     canCarRec = Serial.readBytes(BufferCom, 40);
     if (canCarRec >= 22){
       bTramaRecibida = true;
     }  
  }
}  
