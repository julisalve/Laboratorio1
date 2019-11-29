using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Instrumentos
{
  class Orquesta
  {
    public string nombre;
    public string lugar;
    public tipoOrquesta tipo;
    public List<Muscio> muscios;

    public enum tipoOrquesta {Sinfonica, Camara, Filarmonica};

    public Orquesta () {}
    public Orquesta(string nombre, string lugar, tipoOrquesta tipo)
    {
      this.nombre = nombre;
      this.lugar = lugar;
      this.tipo = tipo;

      this.muscios = new List<Muscio>();
    }

    
    public void setNombre(string nombre)
    {
      this.nombre = nombre;
    }


    public string getOrquestaToString()
    {
      StringBuilder sb = new StringBuilder();
      sb.AppendFormat("Nombre orquesta: {0},\n Lugar {1},\n Tipo {2}\n", this.nombre,this.lugar,this.tipo);

      return sb.ToString();

      // string.concat()
    }
  //  public string getNombreOrquesta()
    //{
     // retur this.nombre;
    //}



   

  public static void  Imprimirorquesta (Orquesta orq)
  {
    StringBuilder sb = new StringBuilder();
    sb.AppendLine(orq.getOrquestaToString());
    if(orq.muscios.Count>0)
    {
      sb.AppendFormat("Lista de musicos \n");
      foreach (Muscio element in orq.muscios)
      {
        sb.AppendFormat("Musico {0}\n", element.nombre);
        sb.AppendFormat("Instrrumento {0} \n", element.instrumento.nombre);
      }
      
    }
    Console.WriteLine("{0}\n", sb.ToString());
    Console.ReadLine();


  }
  }
}
