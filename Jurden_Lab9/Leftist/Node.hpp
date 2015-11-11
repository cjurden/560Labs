
Node::Node()
{
	m_left = nullptr;
	m_right = nullptr;
	m_value = 0;
	m_rank = 0;
}

/*
Node::Node(const Node& other)
{
	this->m_left = nullptr;
	this->m_right = nullptr;
	this->m_value = other.m_value;
	if(other.m_left != nullptr)
	{
		this->m_left = new Node(*other.m_left);
	}
	if(other.m_right != nullptr)
	{
		this->m_right = new Node(*other.m_right);
	}
}
*/

int Node::getValue()
{
	return m_value;
}


Node* Node::getLeft()
{
	return m_left;
}


Node* Node::getRight()
{
	return m_right;
}

int Node::getRank()
{
		return m_rank;
}

void Node::setValue(int value)
{
	m_value = value;
}


void Node::setLeft(Node* left)
{
	m_left = left;
}


void Node::setRight(Node* right)
{
	m_right = right;
}

void Node::setRank(int rank)
{
	m_rank = rank;
}
