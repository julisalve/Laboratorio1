using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
  class Program
  {
    static void Main(string[] args)
    {
      Persona p = new Persona();
      Console.WriteLine("Nombre: {0}, Apellido {1}, Edad {2}", p.nombre, p.apellido, p.getEdad());
      Console.ReadLine(); // es un scanf

      Persona personaDos = new Persona("Mario","Rodriguez",30);
        Console.WriteLine("Nombre: {0}, Apellido {1}, Edad {2}", personaDos.nombre, personaDos.apellido, personaDos.getEdad());
      Console.ReadLine(); // es un scanf

      personaDos.cumplirAnios();
      Console.WriteLine("Nombre: {0}, Apellido {1}, Edad {2}", personaDos.nombre, personaDos.apellido, personaDos.getEdad());
      Console.ReadLine(); // es un scanf
    }


  }
}
