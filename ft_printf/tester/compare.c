/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:22:54 by plpelleg          #+#    #+#             */
/*   Updated: 2021/03/01 17:02:30 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../source/ft_printf.h"
#include "../source/ft_printf.c"
#include "../source/struct_build.c"
#include "../source/extra.c"
#include "../../libft/ft_isdigit.c"
#include "../../libft/ft_strchr.c"
#include "../source/struct_elab.c"
#include "../source/p_character.c"
#include "../source/p_string.c"
#include "../../libft/ft_strlen.c"
#include "../source/p_digit.c"
#include "../../libft/ft_itoa.c"

int main()
{
	int result1;
	int result2;
	char *string;


	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%c");	
	string = "%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c";
	printf("TEST 1...\x1b[0m\nPRINTF:\n");
	result1 = printf(string, ' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	printf("\nFT_PRINTF\n");
	result2 = ft_printf(string, ' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
	
	string = "cia%5c%cne%cro";
	printf("\x1b[33mTEST 2...\x1b[0m\nPRINTF:\n");
	result1 = printf(string, 'o', ' ',  'g');
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 'o',' ', 'g');
	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	string = "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c";
	printf("\x1b[33mTEST 3...\x1b[0m\nPRINTF:\n");
	result1 = printf(string, ' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	printf("\nFT_PRINTF:\n");
		result2 = ft_printf(string, ' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	string = "%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c";
	printf("\x1b[33mTEST 4...\x1b[0m\nPRINTF:\n");
	result1 = printf(string, (char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, (char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	string = "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c";
	printf("\x1b[33mTEST 5...\x1b[0m\nPRINTF:\n");
	result1 = printf(string, (char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, (char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[33mTEST 6...\x1b[0m\nPRINTF:\n");
	string = "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c";
	result1 = printf(string, (char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, (char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[33mTEST 7...\x1b[0m\nPRINTF:\n");
	string = "%c";
	result1 = printf(string, NULL);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, NULL);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[33mTEST 7...\x1b[0m\nPRINTF:\n");
	string = "%.4c";
	result1 = printf(string, 'a');
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 'a');

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
	
	printf("\x1b[33mTEST 8...\x1b[0m\nPRINTF:\n");
	string = "%4c";
	result1 = printf(string, 'a');
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 'a');

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
	
	printf("\x1b[33mTEST 9...\x1b[0m\nPRINTF:\n");
	string = "%05c";
	result1 = printf(string, 'a');
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 'a');

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
	
	printf("\x1b[33mTEST 10...\x1b[0m\nPRINTF:\n");
	string = "%--5c";
	result1 = printf(string, 'a');
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 'a');

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 11...\x1b[0m\nPRINTF:\n");
	string = "%--5c";
	result1 = printf(string, '\0');
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, '\0');

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	
	printf("--------------------------------------\n");
	
	printf("\x1b[33mTEST 12...\x1b[0m\nPRINTF:\n");
	string = "%-05c";
	result1 = printf(string, 'c');
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 'c');

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
	printf("______________________________________\n");
	printf("______________________________________\n");
	printf("--------------------------------------\n");
	
	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%s");	
	printf("\x1b[33mTEST 1...\x1b[0m\nPRINTF:\n");
	string = "%s";
	result1 = printf(string, "ao");
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, "ao");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 2...\x1b[0m\nPRINTF:\n");
	string = "%s";
	result1 = printf(string, "testing testing");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "testing testing");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 3...\x1b[0m\nPRINTF:\n");
	string = "%s%s";
	result1 = printf(string, "hello", "world");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "hello", "world");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST4...\x1b[0m\nPRINTF:\n");
	string = "..%s stuff %s";
	result1 = printf(string, "a", "b");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "a", "b");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 5...\x1b[0m\nPRINTF:\n");
	string = "this %s is empty";
	result1 = printf(string, "");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 6...\x1b[0m\nPRINTF:\n");
	string = "this %s is %s";
	result1 = printf(string, "hello", "");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "hello", "");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 7...\x1b[0m\nPRINTF:\n");
	string = "%s%s%s";
	result1 = printf(string, "1", "2", "3's a charm");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "1", "2", "3's a charm");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 8...\x1b[0m\nPRINTF:\n");
	string = "%32s";
	result1 = printf(string, "abc");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "abc");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 9...\x1b[0m\nPRINTF:\n");
	string = "%16s";
	result1 = printf(string, "nark nark");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "nark nark");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	

	printf("\x1b[33mTEST 10...\x1b[0m\nPRINTF:\n");
	string = "%5s";
	result1 = printf(string, "goes over");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "goes over");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 11...\x1b[0m\nPRINTF:\n");
	string = "%-32s";
	result1 = printf(string, "abc");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "abc");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 12...\x1b[0m\nPRINTF:\n");
	string = "%7.5s";
	result1 = printf(string, "yolo");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "yolo");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 13...\x1b[0m\nPRINTF:\n");
	string = "%7.5s";
	result1 = printf(string, "bombastic");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "bombastic");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 14...\x1b[0m\nPRINTF:\n");
	string = "%-7.5s";
	result1 = printf(string, "yolo");
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, "yolo");

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 15...\x1b[0m\nPRINTF:\n");
	string = "hello, %s.";
	result1 = printf(string, NULL);
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, NULL);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 16...\x1b[0m\nPRINTF:\n");
	string = "%32s.";
	result1 = printf(string, NULL);
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, NULL);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 17...\x1b[0m\nPRINTF:\n");
	string = "%-32s";
	result1 = printf(string, NULL);
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, NULL);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	
	
	printf("\x1b[33mTEST 17...\x1b[0m\nPRINTF:\n");
	string = "%.03s";
	result1 = printf(string, NULL);
	printf("\nFT_PRINTF:\n");	
	result2 = ft_printf(string, NULL);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
	printf("______________________________________\n");
	printf("______________________________________\n");
	printf("--------------------------------------\n");
	
	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 1...\x1b[0m\nPRINTF:\n");
	string = "%.6d";
	result1 = printf(string, -3);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, -3);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 2...\x1b[0m\nPRINTF:\n");
	string = "%.5d";
	result1 = printf(string, 2);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 2);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");	

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 3...\x1b[0m\nPRINTF:\n");
	string = "%05d";
	result1 = printf(string, 43);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 43);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 4...\x1b[0m\nPRINTF:\n");
	string = "%05d";
	result1 = printf(string, -43);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, -43);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 5...\x1b[0m\nPRINTF:\n");
	string = "%7d";
	result1 = printf(string, 33);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 33);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 6...\x1b[0m\nPRINTF:\n");
	string = "%08.5d";
	result1 = printf(string, 8375);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 8375);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 7...\x1b[0m\nPRINTF:\n");
	string = "%8.5d";
	result1 = printf(string, 34);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 34);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 6...\x1b[0m\nPRINTF:\n");
	string = "%8.3d";
	result1 = printf(string, 8375);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 8375);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 7...\x1b[0m\nPRINTF:\n");
	string = "%010.5d";
	result1 = printf(string, -216);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, -216);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 8...\x1b[0m\nPRINTF:\n");
	string = "%07d";
	result1 = printf(string, -54);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, -54);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 9...\x1b[0m\nPRINTF:\n");
	string = "%.0d";
	result1 = printf(string, 0);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 0);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 10...\x1b[0m\nPRINTF:\n");
	string = "%08.5d";
	result1 = printf(string, 0);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 0);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 11...\x1b[0m\nPRINTF:\n");
	string = "%-5.d";
	result1 = printf(string, 0);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 0);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 12...\x1b[0m\nPRINTF:\n");
	string = "%5.0d";
	result1 = printf(string, 0);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 0);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 13...\x1b[0m\nPRINTF:\n");
	string =" %-0*.0d*0 ";
	result1 = printf(string, 21, -1011);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, 21, -1011);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");

	printf("\x1b[36mTESTING %s\n\x1b[33m\n", "%d");	
	printf("\x1b[33mTEST 13...\x1b[0m\nPRINTF:\n");
	string =" --0*%0*.0d*0 0*%0*.10d*0-- ";
	result1 = printf(string, -21, 2147483647, 21, -2147483648);
	printf("\nFT_PRINTF:\n");
	result2 = ft_printf(string, -21, 2147483647, 21, -2147483648);

	if (result1 == result2)
		printf("\n				\x1b[32mVAL: OK\x1b[0m\n");
	else
		printf("\n				\x1b[31mVAL: KO %d %d\x1b[0m\n", result1, result2);
	printf("--------------------------------------\n");
}
