using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Instrumentos
{
  class Instrumentos
  {
    public string nombre;
    public tipoInstr tipo;

    public enum tipoInstr {Viento, Cuerdas};

    public Instrumentos () { }
    public Instrumentos(string nombre, tipoInstr tipo)
    {
      this.nombre = nombre;
      this.tipo = tipo;
    }

    public void setNombreInstr(string nombre)
    {
      this.nombre = nombre;
    }

    public string getInstrumentoToString()
    {
      StringBuilder sbInstr = new StringBuilder();
      sbInstr.AppendFormat("Nombre : {0},\n Tipo {1}\n", this.nombre,this.tipo);
      return sbInstr.ToString();
    }
  }
}
