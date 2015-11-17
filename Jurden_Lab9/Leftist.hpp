Leftist::Leftist()
{
  root = nullptr;
}

LNode* Leftist::merge(LNode* h1, LNode* h2)
{
  //cout<<"merging "<<endl;
  if(h1 == nullptr)
  {
    //cout<<"h1 is null returning "<<h2->value<<endl;
    return h2;
  }
  else if(h2 == nullptr)
  {
    //cout<<"h2 is null returning "<<h1->value<<endl;
    return h1;
  }
  else if(h1->value > h2->value)
  {
    std::swap(h1, h2);
  }
  h1->right =  merge(h1->right, h2);
  setRanks(h1);
  if(h1->left == nullptr)
  {
      std::swap(h1->left, h1->right);
  }
  else if(h1->left->getRank() < h1->right->getRank())
  {
    std::swap(h1->left, h1->right);
  }
  //cout<<"returning "<<h1->value<<endl;
  return h1;
}

void Leftist::deleteMin(Leftist* h)
{
  LNode* h1 = h->root->left;
  LNode* h2 = h->root->right;
  delete h->root;
  merge(h1, h2);
}

void Leftist::insert(int x, LNode*& h)
{
  //cout<<"inserting "<<x<<endl;
  LNode* r = new LNode();
  r->value = x;
  h = merge(h,r);
}

int Leftist::adjustRank(LNode* r)
{
  if(r->left == nullptr || r->right == nullptr)
  {
    return 1;
  }
  else
  {
    return std::min(1 + adjustRank(r->left), 1+adjustRank(r->right));
  }
}

void Leftist::setRanks(LNode* h)
{
  if(h == nullptr)
  {
    return;
  }
  else
  {
    h->setRank(adjustRank(h));
    setRanks(h->left);
    setRanks(h->right);
  }
}

void Leftist::print(LNode* subtree, Order order)
{
	if(subtree==nullptr)
	{
		return;
	}
	if(order == PRE_ORDER)
	{
		std::cout<<subtree->value<<", ";
		print(subtree->left, order);
		print(subtree->right, order);
	}
	if(order == IN_ORDER)
	{
		print(subtree->left, order);
		std::cout<<subtree->value<<", ";
		print(subtree->right, order );
	}
}

void Leftist::print(LNode* subtree, Order order, std::queue<LNode*> q)
{
	if (order == LEVEL_ORDER)
	{
		if(subtree->left!= nullptr)
		{
			q.push(subtree->left);
		}
		if(subtree->right!= nullptr)
		{
			q.push(subtree->right);
		}
		LNode* x = q.front();
		std::cout << x->value << " ";
    q.pop();
		while(q.front() != nullptr)
		{
		print(q.front(), LEVEL_ORDER, q);
		}
	}
}