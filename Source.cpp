using namespace System;

int main() {
	const int LARGURA_TELA = 160;
	const int ALTURA_TELA = 50;

	const int JOGADOR_TAMANHO = 1;
	const Char desenho_jogador = (Char) 9632;
	const Char desenho_tiro = (Char) 186;
	
	const int INIMIGO_TAMANHO = 5;
	const Char desenho_inimigo = (Char) 9608;
	int inimigo_x = 0;
	int inimigo_y = 3;
	int inimigo_direcao = 1;

	// GameState (jogo_estado):
	// 0 - Menu principal;
	// 1 - Gameplay;
	// 2 - Gameover;
	int jogo_estado = 0;
	int jogador_x = 22;
	int jogador_y = 22;

		Console::CursorVisible = false;
		Console::SetWindowSize(LARGURA_TELA, ALTURA_TELA);	
		Console::SetBufferSize(LARGURA_TELA, ALTURA_TELA);

		ConsoleKeyInfo cki;

	bool jogador_atirando = false;

	int tiro_x;
	int tiro_y; 

	int acerto = 0;

		for(;;) {
			switch(jogo_estado) {
				case 0:
					Console::BackgroundColor = ConsoleColor::White;
					Console::Clear();

					Console::SetCursorPosition(0,1);
					Console::ForegroundColor = ConsoleColor::Red;
							Console::WriteLine("                                                                                                                    ¨¨¨¨¨¨¨¨          **      **            ***");
							Console::WriteLine(" MMMMMMMM               MMMMMMMM     OOOOOOOOO     BBBBBBBBBBBBBBBBB        ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨                                     ** *    ** *        * * ");
							Console::WriteLine(" M:::::::M             M:::::::M   OO:::::::::OO   B::::::::::::::::B                                                                   *** *   *** **    * * *");
							Console::WriteLine(" M::::::::M           M::::::::M OO:::::::::::::OO B::::::BBBBBB:::::B                  ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨                            **************** * * * ");
							Console::WriteLine(" M:::::::::M         M:::::::::MO:::::::OOO:::::::OBB:::::B     B:::::B                                                                ***##*************** * *");
							Console::WriteLine(" M::::::::::M       M::::::::::MO::::::O   O::::::O  B::::B     B:::::B                                                               ***##***************** * ");
							Console::WriteLine(" M:::::::::::M     M:::::::::::MO:::::O     O:::::O  B::::B     B:::::B                                                               **##******************* *");
							Console::WriteLine(" M:::::::M::::M   M::::M:::::::MO:::::O     O:::::O  B::::BBBBBB:::::B        ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨       ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨              ************************ ");
							Console::WriteLine(" M::::::M M::::M M::::M M::::::MO:::::O     O:::::O  B:::::::::::::BB                                                               ********    ***************");
							Console::WriteLine(" M::::::M  M::::M::::M  M::::::MO:::::O     O:::::O  B::::BBBBBB:::::B                                                             *********  **      *********");
							Console::WriteLine(" M::::::M   M:::::::M   M::::::MO:::::O     O:::::O  B::::B     B:::::B                        ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨      *******   ***        ********");
							Console::WriteLine(" M::::::M    M:::::M    M::::::MO:::::O     O:::::O  B::::B     B:::::B                                                          **** ***  ***         ********");
							Console::WriteLine(" M::::::M     MMMMM     M::::::MO::::::O   O::::::O  B::::B     B:::::B      ¨¨¨¨¨¨¨¨¨                                           *** ***  ****         ********");
							Console::WriteLine(" M::::::M               M::::::MO:::::::OOO:::::::OBB:::::BBBBBB::::::B                                                           ******  ***         *  ******");
							Console::WriteLine(" M::::::M               M::::::M OO:::::::::::::OO B:::::::::::::::::B           ¨¨¨¨¨¨¨¨                    ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨    ****  ***         *  *******");
							Console::WriteLine(" M::::::M               M::::::M   OO:::::::::OO   B::::::::::::::::B                                                                  ***    ***** *   *******");
							Console::WriteLine(" MMMMMMMM               MMMMMMMM     OOOOOOOOO     BBBBBBBBBBBBBBBBB              ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨                              * * * *   ** ** **");
							Console::WriteLine("                                                                                                                                              ** **  *  ** ** *");
					Console::SetCursorPosition(0,21);
							Console::WriteLine(" FFFFFFFFFFFFFFFFFFFFFFIIIIIIIIII      GGGGGGGGGGGGGHHHHHHHHH     HHHHHHHHHTTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR      SSSSSSSSSSSSSSS ");
							Console::WriteLine(" F::::::::::::::::::::FI::::::::I   GGG::::::::::::GH:::::::H     H:::::::HT:::::::::::::::::::::TE::::::::::::::::::::ER::::::::::::::::R   SS:::::::::::::::S");
							Console::WriteLine(" F::::::::::::::::::::FI::::::::I GG:::::::::::::::GH:::::::H     H:::::::HT:::::::::::::::::::::TE::::::::::::::::::::ER::::::RRRRRR:::::R S:::::SSSSSS::::::S");
							Console::WriteLine(" FF::::::FFFFFFFFF::::FII::::::IIG:::::GGGGGGGG::::GHH::::::H     H::::::HHT:::::TT:::::::TT:::::TEE::::::EEEEEEEEE::::ERR:::::R     R:::::RS:::::S     SSSSSSS");
							Console::WriteLine("   F:::::F       FFFFFF  I::::I G:::::G       GGGGGG  H:::::H     H:::::H  TTTTTT  T:::::T  TTTTTT  E:::::E       EEEEEE  R::::R     R:::::RS:::::S            ");
							Console::WriteLine("   F:::::F               I::::IG:::::G                H:::::H     H:::::H          T:::::T          E:::::E               R::::R     R:::::RS:::::S            ");
							Console::WriteLine("   F::::::FFFFFFFFFF     I::::IG:::::G                H::::::HHHHH::::::H          T:::::T          E::::::EEEEEEEEEE     R::::RRRRRR:::::R  S::::SSSS         ");
							Console::WriteLine("   F:::::::::::::::F     I::::IG:::::G    GGGGGGGGGG  H:::::::::::::::::H          T:::::T          E:::::::::::::::E     R:::::::::::::RR    SS::::::SSSSS    ");
							Console::WriteLine("   F:::::::::::::::F     I::::IG:::::G    G::::::::G  H:::::::::::::::::H          T:::::T          E:::::::::::::::E     R::::RRRRRR:::::R     SSS::::::::SS  ");
							Console::WriteLine("   F::::::FFFFFFFFFF     I::::IG:::::G    GGGGG::::G  H::::::HHHHH::::::H          T:::::T          E::::::EEEEEEEEEE     R::::R     R:::::R       SSSSSS::::S ");
							Console::WriteLine("   F:::::F               I::::IG:::::G        G::::G  H:::::H     H:::::H          T:::::T          E:::::E               R::::R     R:::::R            S:::::S");
							Console::WriteLine("   F:::::F               I::::I G:::::G       G::::G  H:::::H     H:::::H          T:::::T          E:::::E       EEEEEE  R::::R     R:::::R            S:::::S");
							Console::WriteLine(" FF:::::::FF           II::::::IIG:::::GGGGGGGG::::GHH::::::H     H::::::HH      TT:::::::TT      EE::::::EEEEEEEE:::::ERR:::::R     R:::::RSSSSSSS     S:::::S");
							Console::WriteLine(" F::::::::FF           I::::::::I GG:::::::::::::::GH:::::::H     H:::::::H      T:::::::::T      E::::::::::::::::::::ER::::::R     R:::::RS::::::SSSSSS:::::S");
							Console::WriteLine(" F::::::::FF           I::::::::I   GGG::::::GGG:::GH:::::::H     H:::::::H      T:::::::::T      E::::::::::::::::::::ER::::::R     R:::::RS:::::::::::::::SS ");
							Console::WriteLine(" FFFFFFFFFFF           IIIIIIIIII      GGGGGG   GGGGHHHHHHHHH     HHHHHHHHH      TTTTTTTTTTT      EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR SSSSSSSSSSSSSSS   ");
					Console::SetCursorPosition(66,44);
					Console::ForegroundColor = ConsoleColor::Black;
							Console::Write("Pressione <ENTER> para jogar");
					Console::SetCursorPosition(53,48);
					Console::ForegroundColor = ConsoleColor::Red;
							Console::Write("Copyright Omicron Games - Todos os direitos reservados");

					cki = Console::ReadKey();

					if(cki.Key == ConsoleKey::Enter) {
						jogo_estado = 1;
					}
					else if(cki.Key == ConsoleKey::Escape)
						break;
					break;

				case 1:
					Console::BackgroundColor = ConsoleColor::Black;
					Console::Clear();

				//atualização do jogador
				if( Console::KeyAvailable ) {
					cki = Console::ReadKey();
					if(cki.Key == ConsoleKey::LeftArrow ) {
						jogador_x = jogador_x - 1;
						if( jogador_x == -1 )
							jogador_x = 0;
					}
					
					else if( cki.Key == ConsoleKey::RightArrow ) {
						jogador_x = jogador_x + 1;

						if( jogador_x + JOGADOR_TAMANHO > LARGURA_TELA)
							jogador_x = LARGURA_TELA - JOGADOR_TAMANHO;
					}
					//else if(cki.Key == ConsoleKey::Spacebar && ! jogador_atirando ) {
					//	tiro_x = jogador_x + (JOGADOR_TAMANHO / 2);
					//	tiro_y = jogador_y;
					//	jogador_atirando = true;
					//}		
				}

				//// atualização do inimigo
				//if(inimigo_direcao == 1 )
				//{
				//	inimigo_x = inimigo_x + 1;
				//	if( inimigo_x + INIMIGO_TAMANHO > LARGURA_TELA )
				//	{
				//		inimigo_direcao = 0;
				//		inimigo_x = inimigo_x - 1;
				//	}
				//}
				//else if(inimigo_direcao == 0 )
				//{
				//	inimigo_x = inimigo_x - 1;
				//	if( inimigo_x < 0 )
				//	{
				//		inimigo_direcao = 1;
				//		inimigo_x = 0;
				//	}
				//	
				//}

				//// atualização tiro
				//if( jogador_atirando == true )
				//{
				//	tiro_y = tiro_y - 1;
				//	if( tiro_y < 0 )
				//	{
				//		jogador_atirando = false;
				//	}
				//	else
				//	{
				//		// colisão
				//		if( tiro_y == inimigo_y)
				//		{
				//			if( tiro_x >= inimigo_x && tiro_x <= inimigo_x + INIMIGO_TAMANHO)
				//			{
				//				acerto = acerto + 1;
				//				jogador_atirando = false;
				//			}
				//		}
				//		
				//	}
				//}

					//desenho personagem
					Char jogador_cabeca = (Char) 9787;
					Char jogador_corpo = (Char) 8224;
					Char jogador_pernas = (Char) 94;
					Console::SetCursorPosition(jogador_x,jogador_y);
					Console::ForegroundColor = ConsoleColor::Red;
					Console::Write(jogador_cabeca);
					Console::SetCursorPosition(jogador_x,jogador_y + 1);
					Console::Write(jogador_corpo);
					Console::SetCursorPosition(jogador_x,jogador_y + 2);
					Console::Write(jogador_pernas);

				//	// inimigo
				//for( int  i = 0; i < INIMIGO_TAMANHO; i++ )
				//{
				//	Console::SetCursorPosition(inimigo_x + i, inimigo_y);
				//	Console::Write(desenho_inimigo);
				//}

				//	// tiro
				//if( jogador_atirando == true )
				//{
				//	Console::SetCursorPosition(tiro_x, tiro_y);
				//	Console::Write(desenho_tiro);
				//}

					////Placar
					//Console::SetCursorPosition(0, 0);
					//Console::Write("Acertos:{0}", acerto);

					//FPS
					System::Threading::Thread::Sleep(25);
					break;
			}
		}

	return 0;
}