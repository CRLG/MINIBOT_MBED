% Fichier d'initialisation des constantes, tables, ...
% Et d'ouverture du modèle
clc;
display ('_________________________________ COMPORTEMENT ROBOT')

display ('Nettoyage du workspace');
clear all;

display ('Intialisation des données du modèle');
Te = 0.02;  % Période d'échantillonnage à 50msec
PI=pi;
%PI=3.1416;

%ID des Moteurs
MOTEUR_ROUE_GAUCHE =1; %MOTEUR_1,
MOTEUR_ROUE_DROITE=2;  % MOTEUR_2

%ID des Servos
SERVO_INCLINAISON=13;
SERVO_BRAS_D=14;
SERVO_BRAS_G=15;
SERVO_BEQUILLE=16;

% butee_max_servo_sd20_14=104
% butee_min_servo_sd20_13=24
% butee_max_servo_sd20_13=143
% butee_min_servo_sd20_15=18
% butee_max_servo_sd20_15=62
% position_initiale_servo_sd20_15=18
% butee_min_servo_sd20_14=15
% position_initiale_servo_sd20_14=24
% position_initiale_servo_sd20_13=143

%SERVO INCLINAISON
SERVO_INCLINAISON_PENCHE = 24;
SERVO_INCLINAISON_DROIT=143;

%SERVO BRAS D
SERVO_BRAS_D_OUVERT = 104;
SERVO_BRAS_D_FERME=5;

%SERVO BRAS G
SERVO_BRAS_G_OUVERT = 62;
SERVO_BRAS_G_FERME=18;

MAX_SPEED_SERVOS = 0;

% Couleur de l'équipe
EQUIPE_JAUNE = 0;
EQUIPE_VERTE = 1;


% ---------------------------------------------------
% BITS DE CONFIGURATION
STT=1; %1 => stratégie d'évitement basique, on s'arrête et quand il n'y a plus d'obstacle on repart
JUST_HOMOLO=1; %1 => on fait juste le programme d'homologation

display ('Ouverture du modèle');
open ModeleRobot.mdl;
display('Modèle Robot ouvert avec succès');

%option Pack and Go : génération du fichier .zip contenant tous les
%fichiers nécessaires à la compilation du modèle dans un autre
%environnement de compilation (CodeBlocks) en utilisant une structure de
%fichiers "à plat" (tous les fichiers sont dans un même répertoire, il n'y
%a aucune arborescence)
set_param(bdroot,'PostCodeGenCommand','packNGo(buildInfo);');
display('Options PackNGo OK');



display ('_________________________________ FIN ROBOT');


