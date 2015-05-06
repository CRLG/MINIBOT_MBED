% Fichier d'initialisation des constantes, tables, ...
% Et d'ouverture du mod�le
clc;
display ('_________________________________ COMPORTEMENT ROBOT')

display ('Nettoyage du workspace');
clear all;

display ('Intialisation des donn�es du mod�le');
Te = 0.02;  % P�riode d'�chantillonnage � 50msec
PI=pi;
%PI=3.1416;

%SERVO actionnant le crochet arriere
SERVO_CROCHET_RANGE = 160;
SERVO_CROCHET_SORTI = 90; 

%SERVO actionnant le Nerf
SERVO_FRUITMOUTHS_INIT = 0;

MAX_SPEED_SERVOS = 0;

% Couleur de l'�quipe
EQUIPE_JAUNE = 0;
EQUIPE_ROUGE = 1;


% ---------------------------------------------------
% BITS DE CONFIGURATION
STT=1; %1 => strat�gie d'�vitement basique, on s'arr�te et quand il n'y a plus d'obstacle on repart
JUST_HOMOLO=1; %1 => on fait juste le programme d'homologation

display ('Ouverture du mod�le');
open ModeleRobot.mdl;
display('Mod�le Robot ouvert avec succ�s');

%option Pack and Go : g�n�ration du fichier .zip contenant tous les
%fichiers n�cessaires � la compilation du mod�le dans un autre
%environnement de compilation (CodeBlocks) en utilisant une structure de
%fichiers "� plat" (tous les fichiers sont dans un m�me r�pertoire, il n'y
%a aucune arborescence)
set_param(bdroot,'PostCodeGenCommand','packNGo(buildInfo);');
display('Options PackNGo OK');



display ('_________________________________ FIN ROBOT');


