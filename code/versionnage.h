#ifndef VERSIONNAGE_H
#define VERSIONNAGE_H

/// \mainpage Documentation EasyTicket
///
/// \section versions_sec Version
/// \subsection v1_1_subsec v1.1
/// Page de connexion avec au moment de la connexion, la création d'un objet Utilisateur.
///
/// Peut importe le login et le mot de passe, on affiche un message contenant le 'toString' de notre objet Utilisateur.
///
/// \subsection v1_2_subsec v1.2
/// Une fois connecté avec un compte 'client', l'utilisateur accède à la page d'accueil (PageAccueilClient).
///
/// Ajout d'un GestionnaireDialogue qui fait le lien entre l'utilisateur et les données.
///
/// \subsection v1_3_subsec v1.3
/// Le bouton de création de ticket mène à une page vierge qui servira pour créer les tickets (PageAjoutTicket).
///
/// Ajout d'un bouton de retour à la page d'accueil quand on est sur la page de création de ticket.
///
/// \subsection v1_4_subsec v1.4
/// Création de la mise en page du formulaire pour créer le ticket.
///
/// Affiche le resultat sur la sortie standard et si jamais il y a des champs invalides.
///
/// \subsection v1_5_subsec v1.5
/// Vérification des champs saisis par l'utilisation lors de la création d'un nouveau ticket.
///
/// Fonctions de vérifications pour le Message du ticket et génération d'un message contenant le descriptif du Ticket créé (sans encore le message).
///
/// \subsection v1_6_subsec v1.6
/// Implémentation de l'ajout de Message dans le Ticket au moment de sa création. Au moment du clic pour créer le Ticket, on affiche les données du Ticket ainsi que le Message ajouté.
///
/// Si tout est ok, on retourne à la page d'accueil (PageAccueilClient).
///
/// \subsection v1_7_subsec v1.7
/// Ajout de la base de donnée au format db avec SQLite.
///
/// Ajout d'une classe GestionnaireBDD pour gérer l'interfaçage avec le bdd.
///
/// - Importer la bdd.
///
/// - Faire un select sur la bdd, etc.
///
/// \subsection v1_8_subsec v1.8
/// Ajout des fonctions pour communiquer avec la bdd :
/// - Au niveau de la connexion.
///
/// - et de l'enregistrement d'un ticket et du message.
///
/// Création des ComboBox en fonction des tables de la BDD.
///
/// \subsection v2_1_subsec v2.1
/// Une fois connecté avec un compte 'Personnel', l'utilisateur accède à la page d'accueil (PageAccueilPersonnel).
///
/// \subsection v2_2_subsec v2.2
/// Correction de l'application pour pouvoir appliquer le polymorphisme :
///
/// - Suppresion de typeUtilisateur(QString id, QString mdp) dans GestionnaireBDD et dans GestionnaireDialogue.
///
/// - Transformation des fonctions qui retourner un Client et un Ingénieur pour n'en faire qu'une qui retourne un Utilisateur
/// dans GestionnaireBDD et GestionnaireDialogue.
///
/// - Application des fonctions estUnClient() et estUnPersonnel() dans PageLogin sur l'Utilisateur.
///
/// \subsection v2_3_subsec v2.3
/// Correction du code suite au retour par mail :
///
/// - Correction du GestionanireDialogue qui était alloué dynamiquement. Instancié automatiquement par MainWindow puis
/// passage par référence à PageLogin, PageAccueilClient, PageAjoutTicket, PageAccueilPersonnel.
///
/// - Ajout des différents delete pour les Page dans le destructeur de MainWindow car alloué dynamiquement avec un New.
///
/// - Correction des problèmes d'incohérences (paramètres avec référence et const, ou passés en copie, dans le même fichier).
///
/// - Correction du QStackedWidget qui était dupliqué lors de la récupération : passée dans les constructeurs de
/// PageLogin, PageAjoutTicket, PageAccueilClient, PageAccueilPersonnel
///
/// - Page principale de la documentation dans versionnage.h à la place de MainWindow.h
///
/// \subsection v2_4_subsec v2.4
/// Le bouton "Demander un ticket" de la PageAccueilPersonnel permet maintenant de récupérer le ticket le plus ancien qui n'a pas été
/// cloturé ou attribué à un Personnel. Il redirige vers la PageResolutionTicket qui n'a pour l'instant qu'un seul bouton "Retour"
/// permettant de retourner à la PageAccueilPersonnel. Si il n'y a pas de tickets sans Personnel, affichage d'une QMessageBox.
///
/// \subsection v2_5_subsec v2.5
/// Correction du code :
/// - Suppresion de la création d'une Categorie/Logiciel/Systeme lorsque l'on set une QComboBox car inutile.
///
/// - Suppression des New liés aux QSqlQuery
///
/// - Passage par référence au lieu de l'objet là où c'est possible
///
/// \subsection v2_6_subsec v2.6
/// - Mise en place de l'interface graphique de la PageResolutionTicket.
///
/// - Affichage des informations du ticket.
///
/// \subsection v2_7_subsec v2.7
/// Mise en place de l'enregistrement d'un nouveau message par un Personnel au moment du traitement d'un Ticket.
///
/// \subsection v2_8_subsec v2.8
/// Ajout de la possibilité de changer la catégorie d'un ticket.
///
/// \subsection v2_9_subsec v2.9
/// Ajout de la possibilité de clore un ticket en lui définissant une date et une heure de cloture.
///
/// \subsection v2_10_subsec v2.10
/// Réinitialisation des champs saisis lors de la création d'un nouveau ticket, si jamais on désire en créer un autre dans la même session.



#endif // VERSIONNAGE_H
