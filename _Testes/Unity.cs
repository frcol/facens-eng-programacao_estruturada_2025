void Update()
{
    if (Input.touchCount > 0)
    {
        Touch touch = Input.GetTouch(0);

        switch (touch.phase)
        {
            case TouchPhase.Began:
                startTouchPosition = touch.position;
                startTime = Time.time;
                break;

            case TouchPhase.Ended:
                float touchDuration = Time.time - startTime;
                float touchDistance = Vector2.Distance(startTouchPosition, touch.position);

                if (touchDuration <= tapTimeThreshold && touchDistance <= tapMovementThreshold)
                {
                    Debug.Log("Tap detectado em: " + touch.position);
                }
                break;
        }
    }
}