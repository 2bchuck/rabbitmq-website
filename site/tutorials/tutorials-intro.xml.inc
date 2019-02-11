<?xml version="1.0" encoding="utf-8" ?>
<div>
  <p>
    RabbitMQ는 메세지를 주고 받는 메세지 중개자입니다.

    우체국처럼 생각하셔도 무방합니다. 우편함에 편지를 넣으면 집배원이 언젠가는 수취인에게 전달해주는 것처럼 말이죠.

    RabbitMQ는 우체통이고, 우체국이면서 집배원입니다.
  </p>

  <p>
    RabbitMQ가 우체국과 다른 점은 종이를 다루지 않는다는 점입니다. 대신 블롭(<em>메세지</em>를 의미합니다)을 받아서 저장하고, 전달합니다.
  </p>

  <p>
    RabbitMQ, and messaging in general, uses some jargon.
  </p>

  <ul>
    <li>
      <p>
        <em>Producing</em> means nothing more than sending.
        A program that sends messages is a <em>producer</em> :

        <div class="diagram">
          <img src="/img/tutorials/producer.png" height="50" />
          <div class="diagram_source">
            digraph {
              bgcolor=transparent;
              truecolor=true;
              rankdir=LR;
              node [style="filled"];
              //
              P1 [label="P", fillcolor="#00ffff"];
            }
          </div>
        </div>
      </p>
    </li>

    <li>
      <p>
        <em>큐</em>는 RabbitMQ에서 사용하는 우체통의 이름입니다.
        Although messages flow through RabbitMQ and your applications, they can only be stored inside a <em>queue</em>.
        A <em>queue</em> is only bound by the host's memory &amp; disk limits, it's essentially a large message buffer.
        Many <em>producers</em> can send messages that go to one queue, and many <em>consumers</em> can try to receive data from one <em>queue</em>.

        This is how we represent a queue:

        <div class="diagram">
         <img src="/img/tutorials/queue.png" height="90" />
         <div class="diagram_source">
           digraph {
             bgcolor=transparent;
             truecolor=true;
             rankdir=LR;
             node [style="filled"];
             //
             subgraph cluster_Q1 {
               label="queue_name";
               color=transparent;
               Q1 [label="{||||}", fillcolor="red", shape="record"];
             };
           }
          </div>
        </div>
      </p>
    </li>

    <li>
      <p>
        <em>Consuming</em> has a similar meaning to receiving.
        A <em>consumer</em> is a program that mostly waits to receive messages:

        <div class="diagram">
          <img src="/img/tutorials/consumer.png" height="50" />
          <div class="diagram_source">
          digraph {
            bgcolor=transparent;
            truecolor=true;
            rankdir=LR;
            node [style="filled"];
            //
            C1 [label="C", fillcolor="#33ccff"];
          }
          </div>
        </div>
      </p>
    </li>
  </ul>

  <p>
    Note that the producer, consumer, and broker do not have to reside on the same host; indeed in most applications they don't.
    An application can be both a producer and consumer, too.
  </p>
</div>
