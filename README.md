----------	PROGRAMAREA CALCULATOARELOR	 ----------

TASK 1:

Task-ul 1 este modularizat pe realizarea separata a primelor n-1 linii de
ultima. Se incepe cu un for de la i = 0 la n-1 pentru a trata toate liniile, in
afara de ultima. Urmatoarele 2 for-uri au rolul de a completa figura cu
space-uri (j-ul) si caracterul selectat (k-ul). Intrucat triunghiul este unul
dreptunghic echilateral, ultima linie va avea un numar total de n caractere.
Asadar, primele n-1 sunt umplute cu space-uri, in timp ce ultimul cu caracterul
dorit.

TASK 2, 3:

Functiile show_map_0/1/2/3 si move_pos_0/1/2/3 sunt hardcode-ate pentru
numarul de obstacole posibile ( 0 <= P <= 3 ). Astfel, show_map_0 este pentru
cazul in care nu este niciun obstacol, in timp ce move_pos_3 va realiza muta-
rile necesare pentru un joc cu 3 obstacole. Voi explica functionalitatea
show_map_3 si move_pos_3, intrucat celelalte sunt analog lor, doar ca mai mici,
neavand lucruri suplimentare.

show_map_3: deoarece harta are dimensiunea NxM si este separata pe fiecare parte
			de un rand/coloana de stelute, for-urile prin care se va reprezenta
			vor contine N+2, respectiv M+2 pasi. Astfel, daca i este egal cu 
			prima sau ultima linie, sau daca j este egal cu prima sau ultima co-
			loana, harta va fi umpluta cu stelute. Variabilele x, y reprezinta
			coordonatele eroului (ATENTIE! initial am considerat (x,y) ca fiind
			(linie, coloana); pentru a nu modifica toate functiile, am schimbat
			pozitia in care se apeleaza la parametri), in timp ce (l,c), (l2,c2)
			, (l3,c3) reprezinta coordonatele obstacolelor. De asemenea, ob-
			stacolele sunt fie mobile, fie fixe, lucru ce va fi stabilit de
			caracterele m, m2 si m3. Asadar, daca pozitia ce urmeaza a fi
			printata coincide cu pozitia uneia dintre coordonate, acolo se va
			afisa caracterul x, specific obstacolelor.

move_pos_3: avand in vedere ca nu este permisa utilizarea tablourilor multi-
			dimensionale, mecanismul de implementare se bazeaza pe modificarea
			unor variabile care vor schimba pozitia elementelor in afisarea
			hartii. Functia verifica caracterul introdus de la tastatura,
			corespunzator miscarii dorite de jucator. Se verifica daca misca-
			rea se poate face, daca nu, simbolul va ramane cel de runda prece-
			denta. Este setat un count, initializat cu 0, care va stabili
			in ce ture trebuie sa se miste obstacolele mobile (restul impartirii
			la 2 trebuie sa dea 1 pentru a fi incepand cu a 2-a tura). Pentru
			obstacolele mobile, exista 8 directii posibile, fiecare verificata
			printr-un if. La finalul functiei, count-ul va creste pentru a
			asigura continuitatea corecta a miscarilor obstacolelor.

Au fost folositi pointeri DOAR pentru a usura citirea codului si de a
face vizibila modularizarea. Se poate face trecerea la varianta fara pointeri
prin copierea functiilor acolo unde sunt apelate, eliminandu-i pe toti, dar
codul ar fi foarte greu de inteles si s-ar multiplica unde nu este cazul.
	Dupa declararea variabilelor necesare si citirea input-ului, se utilizeaza
un switch care trece prin toate cazurile posibile pentru P (0, 1, 2, 3). Analog
ca la functii, voi explica doar case 3, deoarece este la fel ca celelalte, avand
cod suplimentar. Dupa citire, se afiseaza mapa, si se va trece intr-un while
care verifica pozitia de victorie. Dupa aceea, se va citi miscarea utilizatoru-
lui pana la iesirea din while cauzata de unul din urmatoarele: dorinta de a iesi
din joc (q), pierderea jocului (coordonatele dupa o runda ale eroului coincid cu
coordonatele unuia/ mai multor obstacole, irelevant pentru ca se suprapun), 
castigarea jocului (coordonatele eroului devin (N,M) ). Daca niciuna din acestea
nu este indeplinita, se va afisa harta pentru finalul turei si se va continua
cu urmatoarea runda.
	Am intampinat dificultati la scanarea caracterelor, deoarece se luau in con-
siderare si newline/space, asa ca in unele locuri este folosita sintaxa
scanf(" %c", ...), cu spatiu, ori din header-ul ctype, functia isspace, care
verifica daca caracterul este spatiu. In situatia de fata, daca este spatiu, 
nu va face miscarile respectiva si nu va afisa harta.
