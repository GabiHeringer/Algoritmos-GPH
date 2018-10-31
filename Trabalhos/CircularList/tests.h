//Testes para verificar os métodos da classe CirularList

TEST(LIST, Constructor){
	CircularList CircularList;

	ASSERT_TRUE(CircularList.position == NULL);
}

TEST(LIST, Is_Empty){
	CircularList CircularList;

	ASSERT_TRUE(CircularList.IsEmpty());
}

TEST(LIST, Get_Position_After){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	
	ASSERT_EQ(5, CircularList.GetPosition());
}

TEST(LIST, Get_Position_Before){
	CircularList CircularList;
	CircularList.AddBeforePosition(5);
	CircularList.AddBeforePosition(6);

	ASSERT_EQ(5, CircularList.GetPosition());
}

TEST(LIST, Get_Position_After_and_Before){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddBeforePosition(6);
	
	ASSERT_EQ(5, CircularList.GetPosition());
}

TEST(LIST, Empty_Get_Position){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.GetPosition(), std::invalid_argument);
}


TEST(LIST, Get_Next_After){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);
	ASSERT_EQ(7, CircularList.GetNext());
}


TEST(LIST, Get_Next_Before){
	CircularList CircularList;
	CircularList.AddBeforePosition(5);
	CircularList.AddBeforePosition(6);
	CircularList.AddBeforePosition(7);
	ASSERT_EQ(6, CircularList.GetNext());
}

TEST(LIST, Get_Next_After_and_Before){
	CircularList CircularList;
	CircularList.AddBeforePosition(5);
	CircularList.AddBeforePosition(7);
	CircularList.AddAfterPosition(6);
	ASSERT_EQ(6, CircularList.GetNext());
}

TEST(LIST, Empty_Get_Next){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.GetNext(), std::invalid_argument);
}

TEST(LIST, Get_Previous_After){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);

	ASSERT_EQ(6, CircularList.GetPrevious());
}

TEST(LIST, Get_Previous_Before){
	CircularList CircularList;
	CircularList.AddBeforePosition(5);
	CircularList.AddBeforePosition(6);
	CircularList.AddBeforePosition(7);

	ASSERT_EQ(7, CircularList.GetPrevious());
}

TEST(LIST, Get_Previous_After_and_Before){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddBeforePosition(7);
	CircularList.AddBeforePosition(8);

	ASSERT_EQ(8, CircularList.GetPrevious());
}

TEST(LIST, Empty_Get_Previous){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.GetPrevious(), std::invalid_argument);
}


TEST(LIST, Add_and_Get_Middle){
	CircularList CircularList;

	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);
	CircularList.AddInTheMiddle(1, 8);

	ASSERT_EQ(8, CircularList.GetMiddle(2));
}

TEST(LIST, Empty_Add_Middle){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.AddInTheMiddle(1, 5), std::invalid_argument);
}

TEST(LIST, Empty_Get_Middle){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.GetMiddle(5), std::invalid_argument);
}

TEST(LIST, Pop_PositionN){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);

	CircularList.PopPositionN();
	ASSERT_EQ(7, CircularList.GetPosition());
}



TEST(LIST, Total_Empty){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);

	CircularList.PopPositionN();
	CircularList.PopPositionN();
	CircularList.PopPositionN();
	ASSERT_TRUE(CircularList.IsEmpty());
}

TEST(LIST, Empty_Pop_PositionN){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.PopPositionN(), std::invalid_argument);
}

TEST(LIST, Pop_PositionP){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);

	CircularList.PopPositionP();
	ASSERT_EQ(6, CircularList.GetPosition());
}

TEST(LIST, Empty_Pop_PositionP){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.PopPositionP(), std::invalid_argument);
}

TEST(LIST, Pop_Element){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);
	CircularList.AddAfterPosition(8);

	CircularList.PopElement(2);
	ASSERT_EQ(6, CircularList.GetMiddle(2));
}

TEST(LIST, Empty_Pop_Element){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.PopElement(2), std::invalid_argument);
}

TEST(LIST, Next_Node){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);
	
	CircularList.NextNode();
	ASSERT_EQ(7, CircularList.GetPosition());
	ASSERT_EQ(5, CircularList.GetPrevious());
	ASSERT_EQ(6, CircularList.GetNext());
}

TEST(LIST, Empty_Next_Node){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.NextNode(), std::invalid_argument);
}

TEST(LIST, Previous_Node){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);
	
	CircularList.PreviousNode();
	ASSERT_EQ(6, CircularList.GetPosition());
	ASSERT_EQ(7, CircularList.GetPrevious());
	ASSERT_EQ(5, CircularList.GetNext());
}

TEST(LIST, Empty_Previous_Node){
	CircularList CircularList;
	
	ASSERT_THROW(CircularList.PreviousNode(), std::invalid_argument);
}

TEST(LIST, Has_Value){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddBeforePosition(7);
	CircularList.AddInTheMiddle(2, 8);	

	ASSERT_TRUE(CircularList.Value(8));
}

TEST(LIST, Has_No_Value){
	CircularList CircularList;
	CircularList.AddAfterPosition(5);
	CircularList.AddAfterPosition(6);
	CircularList.AddAfterPosition(7);

	ASSERT_FALSE(CircularList.Value(20));
}
