piano di battaglia: 

normalizzare Makefile:
	trovare la voglia

binding_add_new() era incompleta, ma soprattutto avevamo lo split buggato, quindi l'env non si riempiva. Adesso va.
Chiaramente, dopo aver mostrato il prompt, il programma si chiude al primo comando che gli si dà, però è già qualcosa, dai :)

Michele: iniziato error_hand ma da completare, sono seimila stampe
		tokenizzatore (dovrebbe) poter riconoscere le variabili d'ambiente 
Claudio : da fare parse_redir()

report mini debug: just_do_it.c non sto capendo che deve fare
6
sviluppare echo su una foglia:
	creazione di un miniprompt ✅
	tokenizazzione ✅
	parser su unica foglia ✅
	esecutore del comando
