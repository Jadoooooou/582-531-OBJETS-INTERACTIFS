# LES DIFFÉRENTS #DEFINE
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/1.png)  

# Le PB HUB  

## Changer les commandes du key unit, puisqu'il est maintenant controlé par le HUB   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/2.png) 
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/3.png)  

Rajouter les librairies   
`lib_deps =
    M5_PbHub
`   
`#include <M5_PbHub.h>   
M5_PbHub myPbHub;
`   
# TOUCHDESIGNER   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/4.png)  
Un MOVIEFILESIN qui va looper   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/5.png)  
Un MOVIEFILESIN qui va repartir   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/6.png)  
Et finalement un switch   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/7.png)    

## Lier la touche 1 du clavier   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/8.png)  
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/9.png)   
*ATTENTION GROS PROBLÈMES!! NOUS ALLONS DONC CODER EN PYTHON POUR FAIRE CETTE MANOEUVRE*      
Aller dans EDIT -> PREFERENCES -> DATS -> LE PTIT DOSSIER:   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/10.png)   
Aller chercher l'opérateur NULL_INPUT   
`trigger_chop =op("null_input")`   
Puis:   
`def onFrameStart(frame):
    trigger = trigger_chop[0][0]
    return`   
Aller chercher l'opérateur CONSTANT_INDEX   
`index_op = op("constant_index")`    
Puis:   
`def onFrameStart(frame):
    trigger = trigger_chop[0][0]
    if trigger == 1:
    	index_op.par.value0 = 1	
	return
`   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/11.png)   
Lier dans TouchDesigner   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/12.png)   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/13.png)   

# DEVOIR : LIER LE KEY UNIT -> TOUCHDESIGNER  

Lire et envoyer les données du key unit    
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/devoir_vs.png)  
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/devoir_pd.png)  

Ajouter un OSCin qui écoute le bon port. Connecter au NULL pour qu'il reçoit la valeur (1) à la place du KEYBOARD.   
![screenshot1](https://github.com/Jadoooooou/582-531-COURS7-GR2/blob/main/COMPREHENSION_medias/devoir_touch.png)  



