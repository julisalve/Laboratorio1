using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Instrumentos
{
  class Program
  {
    static void Main(string[] args)
    {
      Orquesta orquestaUno = new Orquesta("Orquesta Uno","Quilmes",Orquesta.tipoOrquesta.Filarmonica);
      Console.WriteLine("Nombre {0}, Lugar: {1}, Tipo {2},\n", orquestaUno.nombre, orquestaUno.lugar, orquestaUno.tipo);
      Console.ReadLine();

      Instrumentos instrumentoUno = new Instrumentos("Instrumento Uno", Instrumentos.tipoInstr.Viento);
      Console.WriteLine("Nombre {0}, Tipo {1},\n", instrumentoUno.nombre,instrumentoUno.tipo);
      Console.ReadLine();

      Muscio musicoPrincipal = new Muscio("Carla", "Perez", 26, instrumentoUno);//, orquestaUno
      Console.WriteLine("Nombre {0},\n Apellido {1},\n Edad {2},\n  {3},\n   \n", musicoPrincipal.nombre,musicoPrincipal.apellido,musicoPrincipal.edad,musicoPrincipal.instrumento.getInstrumentoToString());//,musicoPrincipal.orquesta.getOrquestaToString() {4},
      Console.ReadLine();

      Muscio musicoSec = new Muscio("Pepe", "Perez", 26, instrumentoUno);//, orquestaUno
      Console.WriteLine("Nombre {0},\n Apellido {1},\n Edad {2},\n  {3},\n   \n", musicoSec.nombre, musicoSec.apellido, musicoSec.edad, musicoSec.instrumento.getInstrumentoToString());//,musicoPrincipal.orquesta.getOrquestaToString() {4},
      Console.ReadLine();

      orquestaUno.muscios.Add(musicoPrincipal);
      orquestaUno.muscios.Add(musicoSec);

      Orquesta.Imprimirorquesta(orquestaUno);

    }
  }
}
