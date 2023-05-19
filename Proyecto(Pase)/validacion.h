void reales(char *p,int TAM)
{
    int i;
    char tecla;
 
    /*importante inicializar los valores
    ya que la implementacion que hice lo amerita*/
    i = 0;
    p[0] = '\0';
 
    do
    {
        tecla = getch();//atrapa un caracter sin dejar un eco
 
        /*8 es la tecla para eliminar un caracter
        y el i obligaotiamente tiene que ser mayor que cero
        ya que si entra al if y tiene valor cero, el valor de i
        decrementará y p tendría un subindice -1, "p[-1]"¿?*/
        if ( i > 0 && tecla == 8 )
        {
            printf ( "\b \b" );
            p[--i] = '\0';
        }
        else
        {
            /*rango de letras mayusculas y minusculas y 32 es el espacio*/
            if ( (tecla >= 46 && tecla <= 57))
				//( (tecla >= 65 && tecla <= 90)  || (tecla >= 97 && tecla <= 122) || (tecla == 32))
            {
                printf ( "%c", tecla );
                p[i++] = tecla;
            }
        }
    } while ((tecla != 13 || p[0] == '\0') && i < TAM);
    /* 13 inidica el Enter, i tiene que ser menor 
    que TAM pues de lo contrario, estaría accediendo
    a memoria no reservada*/
 
    p[i] = '\0'; /*colocamos el fin de cadena*/  
}

void numeros(char *p,int TAM)
{
    int i;
    char tecla;
 
    /*importante inicializar los valores
    ya que la implementacion que hice lo amerita*/
    i = 0;
    p[0] = '\0';
 
    do
    {
        tecla = getch();//atrapa un caracter sin dejar un eco
 
        /*8 es la tecla para eliminar un caracter
        y el i obligaotiamente tiene que ser mayor que cero
        ya que si entra al if y tiene valor cero, el valor de i
        decrementará y p tendría un subindice -1, "p[-1]"¿?*/
        if ( i > 0 && tecla == 8)
        {
            printf ( "\b \b" );
            p[--i] = '\0';
        }
        else
        {
            /*rango de letras mayusculas y minusculas y 32 es el espacio*/
            if ( (tecla >= 48 && tecla <= 57))
				//( (tecla >= 65 && tecla <= 90)  || (tecla >= 97 && tecla <= 122) || (tecla == 32))
            {
                printf ( "%c", tecla );
                p[i++] = tecla;
            }
        }
    } while ((tecla != 13 || p[0] == '\0') && i < TAM);
    /* 13 inidica el Enter, i tiene que ser menor 
    que TAM pues de lo contrario, estaría accediendo
    a memoria no reservada*/
 
    p[i] = '\0'; /*colocamos el fin de cadena*/
}

void letras (char *p,int TAM)
{
    int i;
    char tecla;
 
    /*importante inicializar los valores
    ya que la implementacion que hice lo amerita*/
    i = 0;
    p[0] = '\0';
 
    do
    {
        tecla = getch();//atrapa un caracter sin dejar un eco
 
        /*8 es la tecla para eliminar un caracter
        y el i obligaotiamente tiene que ser mayor que cero
        ya que si entra al if y tiene valor cero, el valor de i
        decrementará y p tendría un subindice -1, "p[-1]"¿?*/
        if ( i > 0 && tecla == 8 )
        {
            printf ( "\b \b" );
            p[--i] = '\0';
        }
        else
        {
            /*rango de letras mayusculas y minusculas y 32 es el espacio*/
            if ( (tecla >= 65 && tecla <= 90)  || (tecla >= 97 && tecla <= 122) || (tecla == 32))
				//( (tecla >= 48 && tecla <= 57)|| tecla ==46)	
            {
                printf ( "%c", tecla );
                p[i++] = tecla;
            }
        }
    } while ((tecla != 13 || p[0] == '\0') && i < TAM);
    /* 13 inidica el Enter, i tiene que ser menor 
    que TAM pues de lo contrario, estaría accediendo
    a memoria no reservada*/
 
    p[i] = '\0'; /*colocamos el fin de cadena*/  
}
void numerosdui(char *p,int TAM)
{
    int i;
    char tecla;
 
    /*importante inicializar los valores
    ya que la implementacion que hice lo amerita*/
    i = 0;
    p[0] = '\0';
 
    do
    {
        tecla = getch();//atrapa un caracter sin dejar un eco
 
        /*8 es la tecla para eliminar un caracter
        y el i obligaotiamente tiene que ser mayor que cero
        ya que si entra al if y tiene valor cero, el valor de i
        decrementará y p tendría un subindice -1, "p[-1]"¿?*/
        if ( i > 0 && tecla == 8)
        {
            printf ( "\b \b" );
            p[--i] = '\0';
        }
        else
        {
            /*rango de letras mayusculas y minusculas y 32 es el espacio*/
            if ( (tecla >= 22 && tecla <= 57))
				//( (tecla >= 65 && tecla <= 90)  || (tecla >= 97 && tecla <= 122) || (tecla == 32))
            {
                printf ( "%c", tecla );
                p[i++] = tecla;
            }
        }
    } while ((tecla != 13 || p[0] == '\0') && i < TAM);
    /* 13 inidica el Enter, i tiene que ser menor 
    que TAM pues de lo contrario, estaría accediendo
    a memoria no reservada*/
 
    p[i] = '\0'; /*colocamos el fin de cadena*/
}