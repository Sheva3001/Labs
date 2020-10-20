void createFromTail(TList& head)
{
	init(head);
	TList tail=head;
	int n;
	cout << "Введите кол-во элементов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int elem;
		cout << endl << "Введите элемент: ";
		cin >> elem;
		if (isEmpty(head))
		{
			addToHead(head, elem);
			tail = head;
		}
		else
		{
			addAfterNode(tail, elem);
			tail = tail->next;
		}
	}
}


void mergingLists(TList& M1, TList& M2) { //Передаём в функцию 2 списка
	TList p = M1; //Ставим указатели на первый эл-т каждого списка
	TList q = M2; 
	TList pNode;
	if (p->data < q->data) { //Сравниваем первые эл-ты (тот список, у которого первый эл-т меньше будет "главным", к нему будут добавляться эл-ты из другого списка)
		pNode = p; //Ставим вспомогательный указатель на меньший элемент
		M2 = M1; //Указатели на оба списка теперь указывают на главный
	}
	else {
		pNode = q;
		swap(p, q);
		M1 = M2;
	}
	while ((p->next != NULL) && (q->next != NULL)) { //Этот цикл работает пока указатель не окажется на последнем элементе одного из списков
		if (p->next->data > q->data) {           //Если элемент из "главного" списка, который стоит после эл-та на кот. указатель "р", больше, чем элемент
    			pNode = q;                       //второго списка на котором стоит указатель "q", то эл-т "q" вставляется между p и p->next,
 			q = p->next;                     //а указатель p переходит на p->next
			p->next = pNode;                 //Если же элемент "p->next" меньше, чем "q", то "p" переставляется на "p->next" и цикл повторяется
      			pNode = pNode->next;
			p->next->next = q;
			swap(q, pNode);
			p = p->next;
			pNode = p;
		}
		else {
			pNode = pNode->next;
			p = p->next;
		}
	}
	if (q->next == NULL) {   //После цикла, если у нас остаётся один эл-т из второго списка, мы сравниваем его и вставляем в нужное место
		if (p->next->data > q->data) {
			pNode = p->next;
			p->next = q;
			q->next = pNode;
		}
		else {
			p->next->next = q;
		}
		
	}
	if (p->next == NULL) { //Если у нас закончился главный список и во втором осталось больше одного эл-та мы присоединяем остаток второго списка в конец "главного"
		p->next = q;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	TList M1; TList M2;
	createFromTail(M1);
	createFromTail(M2); //Заполняем оба списка
	mergingLists(M1, M2); //Передаём их в функцию
	printList(M1);
	cout << endl;
	printList(M2); //Выводим ОБА списка, чтобы убедится, что оба указателя ведут на первый элемент нового списка
	return 0;
}
