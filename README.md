# 109-2020
Задания по программированию 109 группы.

## Как работать
Каждый заводит себе директорию, название которой совпадает с логином.
Файлы в чужих директориях не изменяем! (Конечно, ничего страшного не случится даже если вы случайно удалите чужой файл, но НЕ ДЕЛАЕМ ЭТОГО). Все делаем внутри "своей" директории.

После некоторых начальных действий, которые нужно выполнить один раз, сценарий работы такой.
* Создаем в "своей" директории новую директорию для задачи. Пусть её имя X. 
* Создаем там нужные файлы, решаем задачу, исправлем ошибки.
* Когда закончена логическая часть (либо вообще все), то добавляем измененные или созданные файлы в коммит (набор изменений). Команда `git add`.
* Сохранем сделанные изменения командой `git commit` (можно считать, что add и commit - две части одного действия).
* Отправляем коммит на сервер (только после этого я смогу его увиеть).

**Бонус!** Вы можете смотреть код своих одногруппников!

### Регистрация
1. Регистрируемся на сайте github.com. Логин выбираете любой.

2. Присылаем мне свой логин. Логин нужен для того, чтобы выдать вам права.

### Если у вас Linux
#### Действия, которые нужно выполнить только один раз
1. Выполняем команду
```
cd
git clone https://github.com/sergadin/109-2020.git
```
В текущей директории должена появиться директория `109-2020`.

2. "Представляемя"
Выполняем команды (нужно указать свои данные)
```
git config --global user.email "ВАШ EMAIL адрес"
git config --global user.email "ВАШЕ ИМЯ"
```

3. Создаем свою папку
Например (замените `Afonin_SA` на свой логин во всех командах!)
```
cd 109-2020
mkdir Afonin_SA
touch Afonin_SA/.gitkeep
```

4. Сохраняем сделанное изменение
```
git add Afonin_SA
git commit -m "Добавлена директория для пользователя Afonin_SA" Afonin_SA
```

5. Отправляем изменения не сервер github.com
```
git push
```


#### Перед началом решения задачи
1. Создаем директорию для задачи с номером `x.y`. Вместо `Afonin_SA` подставляем название своей директории.
```
mkdir ~/109-2020/Afonin_SA/x.y
cd ~/109-2020/Afonin_SA/x.y
```

#### Пишем решение задачи
В директории для задачи (в нашем примере `~/109-2020/Afonin_SA/x.y`) создаем файлы так, как привыкли. Компилируем, запускаем и т.п.

#### Сдача задачи
1. Сохраняем результаты
```
git add ИМЕНА_ФАЙЛОВ
git commit -m "Решение задачи x.y" ИМЕНА_ФАЙЛОВ
```

Имена файлов указываются через пробел. Перечислять нужно только те файлы, которые вы написали (создали или изменили). Например, `find_root.h find_root.c Makefile`.

Изменения, которые были внесены с момента последнего коммита, можно посмотреть командой
```
git status .
```

Комментарий ("Решение задачи x.y") должен кратко описывать то, что было сделано. "Исправлена ошибка...", "Улучшено форматирование" и т.п.

Коммитов может быть много. Сделали что-то логически законченное - выполнили commit. Система контроля версий git позволяет просматривать историю изменений и, при необходимости, "возвращаться" к старой версии. Это удобно, если внесенные исправления что-то случайно испортили.

2. Отправляем результаты на сервер
```
git push
```


3. Пишем письмо с просьбой посмотреть решение

### ЕСЛИ ЧТО-ТО НЕ ТАК
Если вы сделали какие-то изменения, которые не хотите сохранять, то всегда можно вернуться к последнему коммиту. Команда
```
git reset --hard
```
Например, случайно удалили файл.
**Внимание** Эта команда отменит все исправления (во всех файлах!), которые вы делали с последнего коммита. Поэтому коммиты можно делать часто. Получилось что-то законченное (например, написали функцию) - сделали коммит. 

### Windows
Сначала читаем, как работать в Linux. Здесь аналогично, но программа другая. То, что в Linux делается командами, в этой программе делается нажатием на кнопки и через выпадающее меню.

1. Установить Github Desktop
https://desktop.github.com/

2. File -> Clone repository
Выбираем вкладку URL и вводим адрес `https://github.com/sergadin/109-2020.git`

3. Заходим в директорию 109-2020 (в проводнике)
Там, куда вы ее сохранили на предыдущем шаге.

4. Создаем "свою" директорию.

5. Переключаемся в Github Desktop
Должны увидеть список изменений.

6. Вводим комментарий (внизу экрана) и нажимаем commit

7. Справа появится кнопка push

