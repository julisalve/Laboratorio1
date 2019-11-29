using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Instrumentos
{
  class Muscio
  {
    public string nombre;
    public string apellido;
    public int edad;
    public Instrumentos instrumento;
    //public Orquesta orquesta;

    public Muscio(string nombre, string apellido,int edad, Instrumentos instrumento) // , Orquesta orquesta
    {
      this.nombre = nombre;
      this.apellido = apellido;
      this.edad = edad;
      this.instrumento = instrumento;
      //this.orquesta = orquesta;

    }
  }
}
