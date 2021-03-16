# GerenciadorDeTarefas
Na sociedade repleta de tecnologia em que vivemos as pessoas são frequentemente demandadas por um número
expressivo de tarefas a serem realizadas a cada dia, o que requer planejamento e organização. Essas tarefas
consomem um tempo determinado para serem realizadas (duração) e normalmente tem um prazo para serem
concluídas, também conhecido como deadline. Além de possuírem tempo final, algumas dessas também possuem um
tempo de início, que indica o momento em que a tarefa será disponibilizada. Por exemplo, uma aula de estrutura de
dados inicia as 15:20h do dia 15/12/2020 e termina as 17:00h. Ou seja, ela tem tempo inicial, duração e deadline. Em
um outro exemplo, a preparação dessa aula não tem hora para começar, consome um tempo equivalente à duração
da aula e o deadline é o início da aula, nesse caso, 15:20h do dia 15/12/2020.


1 – Deve permitir que o usuário cadastre uma tarefa conforme os dados descritos no item 2 desse enunciado.
Importante controlar para que não existam IDs repetidos.
2 – Deve exibir as tarefas cadastradas.
3 – Deve excluir uma tarefa de acordo com o ID informado.
4 – Permite editar uma das informações em um ID específico.
5 – Ler um arquivo de tarefas. O arquivo deve seguir o seguinte formato:
N
0, NOME, INÍCIO, DURAÇÃO, DEADLINE
1, NOME, INÍCIO, DURAÇÃO, DEADLINE
2, NOME, INÍCIO, DURAÇÃO, DEADLINE
...
N, NOME, INÍCIO, DURAÇÃO, DEADLINE
6 – Gerar o arquivo de tarefas do item 5 desse menu com base nos registros armazenados na memória atual do
programa.
7 – Computar o conjunto de tarefas que o usuário deve realizar no dia de forma a maximizar o número de tarefas
realizadas e o cumprimento de deadlines. Essa opção deve informar caso alguma tarefa tenha o deadline ultrapassado.
8 – Registrar em um arquivo as tarefas programadas para o dia. O formato do arquivo deve seguir o padrão do item 5
desse menu.
