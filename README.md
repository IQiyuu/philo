# philo 🍝

Implémentation du problème des **philosophes** en C, réalisée dans le cadre du cursus **42**.

Le projet consiste à simuler plusieurs philosophes assis autour d'une table, qui doivent alternativement **manger, dormir et réfléchir**, tout en partageant des fourchettes et en évitant la famine, les deadlocks et les conditions de course.

## Fonctionnalités

* 🧵 Un thread par philosophe
* 🍴 Une fourchette représentée par un mutex
* 🔒 Synchronisation avec des mutex
* 🍝 Gestion des cycles manger / dormir / réfléchir
* 💀 Détection de la mort par famine
* ⏱️ Gestion précise du temps en millisecondes
* 🛑 Arrêt de la simulation lorsqu'un philosophe meurt
* 🔢 Possibilité de définir un nombre minimum de repas par philosophe

## Arguments

Le programme s'utilise avec les arguments suivants :

```text
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument                                    | Description                                           |
| ------------------------------------------- | ----------------------------------------------------- |
| `number_of_philosophers`                    | Nombre de philosophes et de fourchettes               |
| `time_to_die`                               | Temps maximal sans manger avant de mourir             |
| `time_to_eat`                               | Temps nécessaire pour manger                          |
| `time_to_sleep`                             | Temps passé à dormir                                  |
| `number_of_times_each_philosopher_must_eat` | Nombre de repas requis avant l'arrêt de la simulation |

Le dernier argument est optionnel.

## Exemple

```bash
./philo 5 800 200 200
```

Avec une condition d'arrêt après un certain nombre de repas :

```bash
./philo 5 800 200 200 5
```

## Sortie

Le programme affiche les différents événements de la simulation :

```text
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
200 3 has taken a fork
...
```

Lorsqu'un philosophe meurt :

```text
800 3 died
```

Le timestamp correspond au temps écoulé depuis le début de la simulation, en millisecondes.

## Synchronisation

Chaque fourchette est protégée par un **mutex** afin d'empêcher plusieurs philosophes de l'utiliser simultanément.

Les threads doivent également être synchronisés pour éviter :

* les **data races** ;
* les **deadlocks** ;
* les accès concurrents aux données partagées ;
* les problèmes d'affichage des messages.

## Concepts étudiés

Ce projet permet de travailler sur plusieurs concepts importants de programmation système :

* Threads avec `pthread`
* Mutex
* Synchronisation entre threads
* Conditions de course (*race conditions*)
* Deadlocks
* Gestion du temps
* `usleep()`
* Gestion de la mémoire
* Création et destruction de threads
* Gestion des ressources partagées

## Fonctions utilisées

Le projet repose notamment sur les fonctions suivantes :

```c
pthread_create()
pthread_join()
pthread_mutex_init()
pthread_mutex_lock()
pthread_mutex_unlock()
pthread_mutex_destroy()
gettimeofday()
usleep()
malloc()
free()
```

## Compilation

Le projet utilise un `Makefile`.

```bash
make
```

Nettoyer les fichiers objets :

```bash
make clean
```

Supprimer les fichiers compilés :

```bash
make fclean
```

Recompiler entièrement :

```bash
make re
```

## Structure

```text
philo/
├── headers/        # Fichiers d'en-tête
├── srcs/           # Sources du projet
├── Makefile
└── README.md
```

## Objectif du projet

L'objectif de **Philosophers** est de comprendre les problématiques liées à la **programmation concurrente** et à la gestion de ressources partagées.

Le projet met particulièrement l'accent sur la synchronisation des threads et la prévention des comportements indéfinis liés aux accès concurrents.

## Auteur

Projet réalisé dans le cadre du **cursus 42**.
