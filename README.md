# Pensamiento algorítmico
Proyecto pensamiento algorítmico MyBook C++.

Las redes sociales han cambiado la forma como nos comunicamos con nuestros amigos. Ahora cada uno de nosotros tiene perfiles en alguna red social para compartir información sobre lo que nos gusta. MyBook es una nueva red social que usted como Ingeniero Javeriano está desarrollando en donde se comparte información de las películas que le gustan a una persona. Para tener un perfil en MyBook, una persona deberá registrar información como: nombres, apellidos, género (masculino o femenino), correo electrónico y fecha de nacimiento. No se permite que menores de edad creen perfiles en esta red social y tampoco se permiten usuarios con el mismo correo electrónico. Deberá existir un usuario de tipo administrador por omisión al iniciar la aplicación, quien será el único que podrá asignar como administrador a alguien más.
Un usuario de MyBook podrá luego de tener un perfil crear la lista de películas que le gustan. El usuario podrá elegir de una lista de películas, que tiene MyBook, las que le han gustado. Las películas son creadas por el administrador de la red social. De cada película se cuenta con la siguiente información: código (número de 2 dígitos), nombre de la película, género y un breve resumen.
MyBook deberá entonces contar con las siguientes opciones:

1.	Registrarse: Se deberá permitir el ingreso de la información de un usuario. Se podrán crear hasta 50 usuarios. De cada dato del usuario, excepto el nombre y apellido, se podrá elegir si es público o no. Si la información es pública, aparecerá en las búsquedas que hagan otros usuarios del directorio de MyBook

2.	Ingreso a MyBook: Esta opción deberá pedir el correo electrónico del usuario que ingresa al sistema y su contraseña y si es administrador mostrará todas las opciones. Si es un usuario normal, deberá mostrar todas las opciones menos la 2.1.
2.1.	Administración: 
2.1.1.	Asignar administradores:
2.1.1.1.	 Buscar usuario por correo: deberá permitir el ingreso de un correo electrónico y mostrará la información de ese usuario.  
2.1.1.2.	 Asignar administrador: permitirá ingresar el correo electrónico y este usuario será asignado como administrador.
2.1.1.3.	 Quitar asignación como administrador: permitirá ingresar el correo electrónico y este usuario dejará de ser administrador. 
2.1.2.	Ver usuarios: mostrará toda la información de los usuarios, ordenados ascendentemente por apellido.

2.1.3.	Películas:
2.1.3.1.	 Crear películas: Se pedirá la información de una película para quedar disponible y ser incluido en las películas favoritas de los usuarios. El sistema deberá asignar automáticamente el código de la película.
2.1.3.2.	 Modificar película: Listará todas las películas disponibles y permitirá modificar la información de una película seleccionada. 
2.1.3.3.	 Eliminar película: eliminará la información de la película del código seleccionado. La película ya no estará disponible para incluirse dentro del listado de películas

2.2.	Perfil
2.2.1.	Modificar perfil: Permitirá modificar la información del usuario.
2.2.2.	 Inactivar perfil: Marcará el usuario como inactivo.  Toda la información será mantenida, pero el usuario inactivo no estará disponible para sus amigos.
2.2.3.	Eliminar información de perfil: Eliminará toda la información que se tiene de un usuario. Solo se podrá eliminar la información de un usuario inactivo.

2.3.	Amigos 
2.3.1.	 Buscar amigos: pedirá el nombre o apellido de un usuario y mostrará el listado de los usuarios que tienen ese nombre o ese apellido, mostrando solamente su información pública.
2.3.2.	 Hacer solicitudes de amistad: pedirá el correo electrónico del usuario al que se le hará la solicitud de amistad. La solicitud le aparecerá a ese usuario cuando liste las solicitudes de amistad pendientes.
2.3.3.	 Ver solicitudes pendientes: Listará las solicitudes de amistad pendientes que se han recibido de otros usuarios.
2.3.4.	 Aceptar solicitudes de amistad: deberá listar las solicitudes de amistad pendientes que se han recibido de otros usuarios y permitirá elegir una de ellas para aceptarla, esta solicitud desaparecerá del listado y ahora aparecerá dentro del listado de amigos.
2.3.5.	 Ver amigos: mostrará un listado con nombres y apellidos de los amigos, sus correos y fechas de nacimiento
2.3.6.	 Ver información de amigo: Pedirá el correo electrónico de un amigo y mostrará la información completa del amigo, incluyendo las películas que le gustan al amigo seleccionado
2.3.7.	 Ver películas en común: Permitirá ver en forma de tabla las películas propias y las películas del amigo seleccionado y marcará las películas que tienen en común
2.3.8.	 Deshacer amistad: con el correo electrónico de un usuario, hará que este ya no aparezca más en el listado de amigos.
2.4.	 Películas:
2.4.1.	 Me gusta: listará las películas disponibles y permitirá seleccionar una de ellas para que aparezca dentro del listado propio de películas favoritas.
2.4.2.	 No me gusta: Listará las películas del listado de favoritas para remover la que sea elegida de dicho listado
2.5.	 Juegos
2.5.1.	 Triqui: pedirá el correo y contraseña del amigo contra el que va a jugar y les permitirá jugar triqui entre los dos. Se almacenará en la opción de juegos, en triqui las estadísticas de partidos jugados, perdidos, ganados y empatados.
2.5.1.1.	Ver estadísticas: Mostrará las estadísticas del triqui.
2.6.	Cerrar sesión: cierra la sesión del usuario que ha ingresado y regresa al menú principal. 

3.	Salir: sale del sistema.

