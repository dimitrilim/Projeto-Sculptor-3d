#ifndef SCULPTOR_H
#define SCULPTOR_H



/** \brief Declaração da struct Voxel
 * O tipo de dado Voxel é armazenado nessa struct
 * \param r g b a isOn
 *
 *
 */

struct Voxel {
  float r,g,b; // Cores
  float a;     // Transparencia
  bool isOn;   // Voxel incluido ou nao
};
/** \brief Classe para moldar os blocos com figuras geométricas simples além de atribuir a cor e salvar em um arquivo off
 *
 * \param
 * \param
 * \return
 *
 */


class Sculptor {
protected:
  Voxel ***v;    // Matriz 3D
  int nx,ny,nz;  // Dimensoes
  float r,g,b,a;// Cor atual do desenho e transparencia
public:

  /** \brief Construtor da classe
   *
   * \param _nx
   * \param _ny
   * \param _nz
   * \remarks Nessa parte é feita a alocação dinamica de memória
   */
  Sculptor(int _nx , int _ny , int _nz);
  /** \brief Destrutor da classe
   * \remarks Liberação da memória alocada
   */

  ~Sculptor();

    /** \brief Função responsavel por atribuir a cor atual do desenho
     *
     * \param _r, _g, _b, _alpha
     * \remarks Essa função recebe valores entre 0 e 1 para as cores vermelha(_r), verde (_g), azul(_b) e a transparencia(alpha). \n
     * Obs: no momento que é definida a cor as funções seguintes do codigo vão atribuir  a cor definida por setColor, para mudar a cor é necessário fazer mais uma chamada da função setColor
     *
     */
  void setColor(float _r, float _g, float _b, float alpha);
  /** \brief Função responsavel por um voxel em uma posição (x,y,z) e deixando ativo (isOn = true)
   *
   * \param x, y, z
   * \return void
   *
   */
  void putVoxel(int x, int y, int z);

  /** \brief Função responsavel por cortar um voxel na posição (x,y,z) e deixando inativo (isOn = false)
   *
   * \param x int
   * \param y int
   * \param z int
   * \return void
   *
   */
  void cutVoxel(int x, int y, int z);

  /** \brief Função responsavel por colocar uma sequencia de voxels em forma de caixa e deixando ativo (isOn = true)
   *
   * \param x0, y0, z0, x1, y1, z1
   * \remarks Ativa os voxels em um intervalo de [x0, x1],[y0, y1] e [z0, z1]
   */
  void putBox(int x0, int y0, int z0, int x1, int y1, int z1);

  /** \brief Função responsavel por cortar uma sequencia de voxels em forma de caixa e deixando inativo (isOn = false)
   *
   * \param x0, x1, y0, y1, z0, z1
   * \remarks Desativa os voxels em um intervalo [x0, x1], [y0, y1] e [z0, z1]
   * \return void
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /** \brief Função responsável por ativar todos os voxels que satisfazem a equação da esfera
   *
   * \param xcenter, ycenter, zcenter, radius
   * \remarks Ativa todos os voxels nas 3 dimensoes da figura, quanto maior o raio mais definida fica a esfera
   *\return void
   */

  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /** \brief Função responsável por desativar todos os voxels que satisfazem a equação da esfera (isOn = false)
   * \param xcenter, ycenter, zcenter, radius
   * \return void
   *
   */

  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

  /** \brief Função responsável por ativar todos os voxels que satisfaz a equação da elipsoide
   *
   * \param xcenter, ycenter, zcenter, rx, ry, rz
   * \remarks Nessa função é possivel criar figuras de formas diferentes de acordo com o raio informado
   * \return void
   */

  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /** \brief Função responsável por desativar todos os voxels que satisfaz a equação da elipsoide
   *
   * \param xcenter, ycenter, zcenter, rx, ry, rz
   * \return void
   *
   */

  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /** \brief Função que grava a escultura em um arquivo OFF
   * \param *filename
   * \remarks Essa função cria um arquivo no formato off em que neste arquivo vai representar uma matriz com (8*nVoxels )Vertices e (6*nVoxels) faces para voxels com isOn = true
   * \return void
   */

  void writeOFF(char *filename);
};

#endif // SCULPTOR_H




