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

%SERVO actionnant le crochet arriere
SERVO_CROCHET_RANGE = 160;
SERVO_CROCHET_SORTI = 90; 

%SERVO actionnant le Nerf
SERVO_FRUITMOUTHS_INIT = 0;

MAX_SPEED_SERVOS = 0;

% Couleur de l'équipe
EQUIPE_JAUNE = 0;
EQUIPE_ROUGE = 1;


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


