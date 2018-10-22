//Testes para verificar a funcionalidade dos overloads de operadores e métodos da classe

TEST(MATRIZ, get_linha){
     Matriz mat(2,2);
     ASSERT_EQ(2, mat.getLinha());
}

TEST(MATRIZ, get_coluna){
     Matriz mat(4,5);
     ASSERT_EQ(5, mat.getColuna());
}


TEST(MATRIZ, operator_brackets){
     Matriz mat (3,3);
     mat[0][0] = 5;
     ASSERT_EQ(5, mat[0][0]);
}

TEST(MATRIZ, operator_assigment){
     Matriz mat(2,2);
     Matriz mat2(2,2);

     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 1;
            mat2[i][j] = 2;
        }
     }
     mat = mat2;
     ASSERT_EQ(2, mat[0][1]);
}

TEST(MATRIZ, operator_plus){
     Matriz mat (2,2);
     Matriz mat2(2,2);
     
     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 1;
            mat2[i][j] = 1;
        }
     }
     
     Matriz mat3 (2,2);
     mat3 = mat + mat2;
     ASSERT_EQ(2, mat3[1][0]);
}

TEST(MATRIZ1, exception_plus){
     Matriz mat (3,3);
     Matriz mat2 (4,5);
  
     ASSERT_THROW((mat+mat2), std::invalid_argument);
}

TEST(MATRIZ, operator_minus){
     Matriz mat (2,2);
     Matriz mat2(2,2);
     
     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 1;
            mat2[i][j] = 1;
        }
     }
     
     Matriz mat3 (mat - mat2);
     ASSERT_EQ(0, mat3[1][0]);
}

TEST(MATRIZ1, exception_minus){
     Matriz mat (3,3);
     Matriz mat2 (2,2);
  
     ASSERT_THROW((mat-mat2), std::invalid_argument);
}

TEST(MATRIZ, operator_asterisk){
     Matriz mat (2,2);
     Matriz mat2(2,2);  
     
     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 2;
            mat2[i][j] = 2;
        }
     }
     
     Matriz mat3 (mat * mat2);
     ASSERT_EQ(8, mat3[0][0]);
}

TEST(MATRIZ1, exception_asterisk){
     Matriz mat (3,3);
     Matriz mat2 (4,4);
  
     ASSERT_THROW((mat*mat2), std::invalid_argument);
}

TEST(MATRIZ, giving_zeros){
     Matriz mat (3,3);
     mat.zero();
     ASSERT_EQ(0, mat[2][1]);
}

